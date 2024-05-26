#include <bits/stdc++.h>
using namespace std;

#define MAX 303000

vector<pair<int, int>> gr[MAX];
int d[MAX];

vector<int> imp;
vector<int> hotels;

int n, m, k, q;
int u, v, w;

void dijkstra(int from)
{
    fill(d, d + n + 1, LLONG_MAX / 2);
    d[from] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({from, d[from]});

    int node, u, w;

    while (!pq.empty())
    {

        node = pq.top().first;
        pq.pop();

        for (auto p : gr[node])
        {
            u = p.first;
            w = p.second;

            if (d[u] > d[node] + w)
            {
                d[u] = d[node] + w;
                pq.push({u, -d[u]});
            }
        }
    }

    return;
}

int main()
{
    cin >> n >> m;

    int i;

    for (i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
    }

    cin >> k;
    for (i = 0; i < k; ++i)
    {
        cin >> u;
        gr[n].push_back({u, 0});
        imp.push_back(u);
    }

    cin >> q;
    for (i = 0; i < q; ++i)
    {
        cin >> u;
        hotels.push_back(u);
    }

    dijkstra(n);

    for (i = 0; i < q; ++i)
    {
        cout << d[hotels[i]] << endl;
    }
}