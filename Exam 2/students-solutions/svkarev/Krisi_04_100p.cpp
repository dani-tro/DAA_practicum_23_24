#include <bits/stdc++.h>
using namespace std;

uint32_t n, m, k, q;

vector<vector<pair<uint32_t, uint32_t>>> G;

vector<uint32_t> important;

vector<bool> visited(n, false);
vector<uint64_t> dist(n, INT64_MAX);

priority_queue<pair<uint32_t, uint32_t>, vector<pair<uint32_t, uint32_t>>, greater<pair<uint32_t, uint32_t>>> pq;

void dijkstra(const vector<uint32_t> &froms)
{
    for (size_t i = 0; i < froms.size(); i++)
    {
        pq.push({0, froms[i]});
        dist[froms[i]] = 0;
    }

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (auto [v, w] : G[u])
        {
            if (visited[v])
                continue;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    G.resize(n);

    dist.resize(n, INT64_MAX);
    visited.resize(n, false);

    for (size_t i = 0; i < m; i++)
    {
        uint32_t x, y, t;

        cin >> x >> y >> t;

        G[x].push_back({y, t});
        G[y].push_back({x, t});
    }

    uint32_t k;
    cin >> k;
    important.resize(k);

    for (size_t i = 0; i < k; i++)
    {
        cin >> important[i];
    }
    
    dijkstra(important);

    uint32_t q;
    cin >> q;
    vector<uint32_t> ans(q);

    for (size_t i = 0; i < q; i++)
    {
        uint32_t question;
        cin >> question;

        ans[i] = dist[question];
    }

    for (size_t i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
