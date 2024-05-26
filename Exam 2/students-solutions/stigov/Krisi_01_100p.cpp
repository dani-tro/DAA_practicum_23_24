#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g[100006];

bool visited[100006];
long long d[100006];

// vector<int> mon;
vector<int> h;

void dijkstra(int x)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, x});
    d[x] = 0;

    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();

        if (visited[v])
            continue;

        visited[v] = true;

        for (auto u : g[v])
        {
            if (d[u.first] > d[v] + u.second)
            {
                d[u.first] = d[v] + u.second;
                pq.push({-d[u.first], u.first});
            }
        }
    }
}

int n, m, k, q;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        g[x].push_back({y, t});
        g[y].push_back({x, t});
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int p;
        cin >> p;
        // mon.push_back(p);
        g[n].push_back({p, 0});
        g[p].push_back({n, 0});
    }

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int p;
        cin >> p;
        h.push_back(p);
    }

    for (int i = 0; i <= n; i++)
    {
        d[i] = INT_MAX;
        visited[i] = false;
    }

    dijkstra(n);

    for (int i = 0; i < h.size(); i++)
    {
        cout << d[h[i]] << endl;
    }

    return 0;
}