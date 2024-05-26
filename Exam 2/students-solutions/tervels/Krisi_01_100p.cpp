#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAXN = 1e5 + 5;
int n, m, k, q;
vector<pair<int, int>> g[MAXN];
int dist[MAXN];
bool visited[MAXN];

void dijkstra(int from)
{
    for (int i = 0; i < n; ++i)
        dist[i] = INT_MAX;

    dist[from] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, from});
    int curr, adj, t;
    
    while (!pq.empty())
    {
        curr = pq.top().second;
        pq.pop();

        if (visited[curr]) continue;
        visited[curr] = true;

        for (auto p : g[curr])
        {
            adj = p.first;
            t = p.second;

            if (dist[adj] > dist[curr] + t)
            {
                dist[adj] = dist[curr] + t;
                pq.push({-dist[adj], adj});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

    cin >> n >> m;
    int u, v, t;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> t;
        g[u].push_back({v, t});
        g[v].push_back({u, t});
    }

    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> u;
        g[n].push_back({u, 0});
    }

    dijkstra(n);

    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> u;
        cout << dist[u] << endl;
    }

    return 0;
}