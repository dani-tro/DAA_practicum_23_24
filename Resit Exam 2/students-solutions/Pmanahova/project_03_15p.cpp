#include <bits/stdc++.h>
using namespace std;

#define MAXN 100007
#define MAXM 200007

long long n, m, a, b, t, v, u, sz;

struct edge
{
    long long bg, end, t;
};

vector<edge> edges;

vector<pair<long long, long long>> g_in[MAXN];
vector<pair<long long, long long>> g_out[MAXN];

long long ans, early[MAXN], late[MAXN], d_in[MAXN];
queue<long long> q;
vector<long long> sorted;

int topological_sort()
{
    long long node = 0;

    while(d_in[node] > 0)
    {
        node++;
        if (node > n - 1) return -1;
    }

    q.push(node);

    while (!q.empty())
    {
        node = q.front();
        q.pop();
        sorted.push_back(node);

        for (auto e : g_out[node])
        {
            v = e.first;
            d_in[v]--;
            if (d_in[v] == 0)
            {
                q.push(v);
            }
        }
        
    }
    return 0;
}

void find_early()
{
    v = sorted[0];
    early[v] = 0;

    sz = sorted.size();

    for (long long i = 1; i <= sz - 1; i++)
    {
        u = sorted[i];
        for (auto e : g_in[u])
        {
            v = e.first;
            t = e.second;

            early[u] = max(early[u], early[v] + t);
        }       
    }
}

void find_late()
{
    fill(late, late + n + 1, LLONG_MAX / 2);

    sz = sorted.size();
    v = sorted[sz - 1];
    late[v] = early[v];

    for (long long i = sz - 2; i >= 0; i--)
    {
        u = sorted[i];
        for (auto e : g_out[u])
        {
            v = e.first;
            t = e.second;

            late[u] = min(late[u], late[v] - t);
        }       
    }   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;
    for (long long i = 0; i < m; i++)
    {
        cin >> a >> b >> t;
        g_out[a].push_back({b, t});
        g_in[b].push_back({a, t});
        d_in[b]++;
        edges.push_back({a, b, t});
    }
    
    int code = topological_sort();
    // if (code == -1) 
    // {
    //     cout << -1 << endl;
    //     return 0;
    // }

    // for (long long v : sorted)
    // {
    //     cout << v << " ";
    // }

    find_early();
    find_late();
    
    cout << early[sorted.back()] << endl;
    for (edge e : edges)
    {
        cout << early[e.bg] << " " << (late[e.end] - e.t) << endl;
    }


    return 0;
}