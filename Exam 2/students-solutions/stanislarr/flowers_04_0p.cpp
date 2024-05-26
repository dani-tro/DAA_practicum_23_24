#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

vector<int> graph[20005];
int in[20005];
bool added[20005];
int n;
int counter;

int k, m, temp;
int u;



bool topoSort() {
    priority_queue<int> pq;
    for (int i = 1; i <= 20005; i++) {
        if (in[i] == 0 && added[i] == true) {
            pq.push(-i);
        }
    }

    while (!pq.empty()) {
        int node = -pq.top();
        pq.pop();

        counter++;
        for (auto v : graph[node]) {
            in[v]--;
            if (in[v] == 0) pq.push(-v);
        }
    }

    return (counter == n);
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> m;
        cin >> temp;
        if (!added[temp]) {
            added[temp] = true;
            n++;
        }
        for (int j = 1; j < m; j++) {
            cin >> u;
            if (!added[u]) {
                added[u] = true;
                n++;
            }
            graph[temp].push_back(u);
            in[u]++;
            temp = u;

        }
    }

    cout << topoSort() << endl;

    return 0;
}