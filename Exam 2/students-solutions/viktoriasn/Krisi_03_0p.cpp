#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

const int MAXN = 100000;
int n, m, k, q;

vector<pair<int, int>> graph[MAXN];
bool visited[MAXN];
int distances[MAXN];
vector<int >places;

void dijkstra(int from) {
    fill(distances, distances + n + 1, INT_MAX / 2);
    fill(visited, visited + n + 1, false);
    //visited[from] = true;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, from });
    distances[from] = 0;
    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();
        if (!visited[curr.second]) {
            visited[curr.second] = true;
            for (pair<int, int> ver : graph[curr.second]) {
                if (distances[ver.second] > distances[curr.second] + ver.first) {
                    distances[ver.second] = distances[curr.second] + ver.first;
                    pq.push({ distances[ver.second], ver.second });
                }
            }
        }
    }

}

int findSmallest() {
    int currSmallest = distances[places[0]];
    for (int i = 1; i < places.size(); i++) {
        if (distances[places[i]] < currSmallest) {
            currSmallest = distances[places[i]];
        }
    }

    return currSmallest;
}


int main() {
    cin >> n >> m;
    size_t x, y, t;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> t;
        graph[x].push_back({ t, y });
        graph[y].push_back({ t, x });
    }

    cin >> k;
    int curr;
    for (int i = 0; i < k; i++) {
        cin >> curr;
        places.push_back(curr);
    }

    cin >> q;
    int h;
    vector<int> results;
    for (int i = 0; i < q; i++) {
        cin >> h;
        dijkstra(h);
       // results.push_back(findSmallest());
        cout << findSmallest()<<endl;
    }
/*
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }
*/
    return 0;
}