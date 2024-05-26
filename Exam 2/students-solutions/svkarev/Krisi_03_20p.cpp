#include <bits/stdc++.h>
using namespace std;

uint32_t n, m, k, q;

vector<vector<pair<uint32_t, uint32_t>>> G;

vector<bool> important;
vector<uint64_t> dist_to_imp;

uint32_t bfs(int from)
{
    uint32_t min_inter = INT_MAX;
    queue<pair<uint32_t, uint32_t>> bfs; // {current, dist}
    vector<bool> visited(n, false);
    bfs.push({from, 0});

    while(!bfs.empty())
    {
        auto [c,d] = bfs.front();
        bfs.pop();

        if(important[c])
        {
            if(min_inter > d)
                min_inter = d;

            continue;
        }

        if(visited[c])
            continue;
        visited[c] = true;

        for(auto [u,w] : G[c])
        {
            bfs.push({u, d+w});
        }
    }
    return min_inter;
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

        ans.push_back(bfs(x));
    }
    
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    
    return 0;
}
