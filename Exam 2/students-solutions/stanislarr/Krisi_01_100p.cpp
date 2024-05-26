#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

#define MAX 100000

int n, m;
int x, y, t;
int k, q;
int temp;
vector<pair<int, int>> graph[MAX];
vector<int> starting;
vector<int> questions;
bool used[MAX];
int dist[MAX];

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    for (auto s : starting) {
        dist[s] = 0;
        used[s] = true;
        for (auto v : graph[s]) {
            int u = v.first;
            int w = v.second;
            if (dist[u] > w) {
                dist[u] = w;
                pq.push({-dist[u], u});
            }
        }
    }

    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        if (used[node]) continue;
        used[node] = true;

        for (auto v : graph[node]) {
            int u = v.first;
            int w = v.second;
            if (dist[u] > dist[node] + w) {
                dist[u] = dist[node] + w;
                pq.push({ -dist[u], u });
            }
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX / 2;
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y >> t;

        graph[x].push_back({ y, t });
        graph[y].push_back({ x, t });
    }

    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> temp;
        starting.push_back(temp);
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> temp;
        questions.push_back(temp);
    }

    dijkstra();

    for (auto q : questions) {
        cout << dist[q] << endl;
    }



    return 0;
}