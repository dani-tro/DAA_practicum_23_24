#include <bits/stdc++.h>
using namespace std;

#define MAX 30300

vector<pair<int, int>> gr[MAX];
int d[MAX];

vector<int> imp;
vector<int> hotels;

int n, m, k, q;
int u, v, w;

void dijkstra(int from)
{
    fill(d, d + n + 1, INT_MAX / 2);
    d[from] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({d[from], from});

    int node, u, w;

    while (!pq.empty())
    {
        node = pq.top().second;
        pq.pop();

        for(auto p : gr[node]) {
            u = p.first;
            w = p.second;

            if (d[u] > d[node] + w) {
                d[u] = d[node] + w;
                pq.push(p);
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
        imp.push_back(u);
    }

    cin >> q;
    for (i = 0; i < q; ++i)
    {
        cin >> u;
        gr[n].push_back({u, 0});
        hotels.push_back(u);
    }

    dijkstra(n);

    for (i = 0; i < q; ++i) {
        cout << hotels[i] << endl;
    }
}