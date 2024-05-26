#include <bits/stdc++.h>
using namespace std;

uint32_t k;

vector<uint32_t> indeg;

vector<vector<uint32_t>> G;

const int maxf = 20001;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    G.resize(maxf);
    indeg.resize(maxf, 0);

    cin >> k;
    for (size_t i = 0; i < k; i++)
    {
        uint32_t p;

        cin >> p;

        vector<uint32_t> g(p);

        for (size_t i = 0; i < p; i++)
        {
            cin >> g[i];
        }
        
        for (size_t i = 0; i < p - 1; i++)
        {
            G[g[i]].push_back(g[i+1]);
            indeg[g[i+1]]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (size_t i = 1; i < maxf; i++)
    {
        if(indeg[i] == 0)
            pq.push(i);
    }

    uint32_t t_sort_c = 0;
    
    while(!pq.empty())
    {
        uint32_t cur = pq.top();
        pq.pop();
        
        t_sort_c++;

        for(auto u : G[cur])
        {
            --indeg[u];

            if(indeg[u] == 0)
                pq.push(u);
        }
    }
    
    cout << (t_sort_c == 20000) << endl;

    return 0;
}
