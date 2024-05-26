#include <bits/stdc++.h>
using namespace std;

uint32_t n, m, k, q;

vector<vector<pair<uint32_t, uint32_t>>> G;

vector<bool> important;
vector<uint64_t> dist_to_imp;

vector<bool> visited(n, false);
vector<uint64_t> dist(n, INT64_MAX);

void dijkstra(uint32_t from)
{
    for (size_t i = 0; i < n; i++)
    {
        dist[i] = INT64_MAX;
        visited[i] = false;
    }
    

    priority_queue<pair<uint32_t, uint32_t>, vector<pair<uint32_t, uint32_t>>, greater<pair<uint32_t, uint32_t>>> pq;

    pq.push({0, from});
    dist[from] = 0;

    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if(visited[u])
            continue;
        visited[u] = true;

        for(auto [v,w] : G[u])
        {
            if(visited[v])
                continue;
            
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});

                if(important[v] && dist[v] < dist_to_imp[from])
                {
                    dist_to_imp[from] = dist[v];
                }
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
    dist_to_imp.resize(n, INT64_MAX);
    important.resize(n, false);

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

    for (size_t i = 0; i < k; i++)
    {
        uint32_t x;
        cin >> x;

        important[x] = true;
    }
    
    uint32_t q;
    cin >> q;

    vector<uint32_t> ans;

    for (size_t i = 0; i < q; i++)
    {
        uint32_t x;
        cin >> x;

        dijkstra(x);

        ans.push_back(dist_to_imp[x]);
    }
    
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    
    return 0;
}
