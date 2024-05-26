
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAXN = 100000;

int n;
vector<pair<int, int>> graph[MAXN];
vector<pair<int, int>> coords;

bool added[MAXN];

int calc(int xi, int xj, int yi, int yj) {
    return ((xi - xj)*(xi-xj)) + ((yi - yj) * (yi - yj));

}


int main() {
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        coords.push_back({ x, y });
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n ; j++) {
            if (i != j) {
                graph[i].push_back({ j, calc(coords[i - 1].first, coords[j - 1].first, coords[i - 1].second, coords[j - 1].second) });
               // graph[j].push_back({ i, calc(coords[j-1].first, coords[i-1].first, coords[j-1].second, coords[i-1].second) });
            }
        }
    }
    int sum = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({ 0, 1 });
    for (pair<int, int> ver : graph[1]) {
        pq.push({ ver.second, ver.first });
    }
   // cout << pq.size();
    added[0] = true;
    while (!pq.empty()) {

        
        pair<int, int> curr = pq.top();
        pq.pop();
       // cout << "w" << curr.first << "v" << curr.second << endl;
        if (!added[curr.second]) {
            sum += curr.first;
            added[curr.second] = true;
            for (pair<int, int> ver : graph[curr.second]) {
                pq.push({ ver.second  ,ver.first });
            }
        }
    }

    cout << sum << endl;
    return 0;
}