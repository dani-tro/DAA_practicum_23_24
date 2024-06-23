#include <bits/stdc++.h>
using namespace std;

#define MAXN 20007

int n, m, k, a, b, v, p, t, node;

struct neighbour
{
    int v, p, t;
};

vector<neighbour> g[MAXN];
bool used[MAXN];
int d[MAXN];
priority_queue<pair<int, int>> pq;

void dijkstra(int from)
{
    fill(d, d + n + 1, 0);
    d[from] = k;
    pq.push({d[from], from});

    while (!pq.empty())
    {
        node = pq.top().second;
        pq.pop();

        if (used[node]) continue;
        used[node] = true;

        for (auto e : g[node])
        {
            v = e.v;
            p = e.p;
            t = e.t;

            if (!used[v])
            {
                if (d[v] < d[node] + p - t)
                {
                    d[v] = d[node] + p - t;
                    pq.push({d[v], v});
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

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> p >> t;
        g[a].push_back({b, p, t});
        g[b].push_back({a, p, t});
    }

    dijkstra(1);

    cout << d[n] << endl;

    return 0;
    
}