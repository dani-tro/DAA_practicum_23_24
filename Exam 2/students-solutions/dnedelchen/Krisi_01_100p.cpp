#include <bits/stdc++.h>
#define MAXN 100003
#define INF 100000003
#define endl '\n'
using namespace std;
int n, m, k, cnt;
int special[MAXN];
int query[MAXN];

struct node
{
    int ver, weight;
    bool operator < (const node &other) const
    {
        return weight > other.weight;
    }
};

vector<node> adj[MAXN];
int dist[MAXN];
bool used[MAXN];
priority_queue<node> q;

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj[from].push_back({to, weight});
        adj[to].push_back({from, weight});
    }

    cin >> k;
    for (int i = 0; i < k; ++i)
        cin >> special[i];

    cin >> cnt;
    for (int i = 0; i < cnt; ++i)
        cin >> query[i];
}

void solve()
{
    for (int i = 0; i < n; ++i)
    {
        dist[i] = INF;
        used[i] = 0;
    }

    for (int i = 0; i < k; ++i)
    {
        dist[special[i]] = 0;
        q.push({special[i], 0});
    }

    while (!q.empty())
    {
        node tmp = q.top();
        q.pop();

        if (!used[tmp.ver] && tmp.weight <= dist[tmp.ver])
        {
            used[tmp.ver] = 1;
            int sz = adj[tmp.ver].size();
            for (int i = 0; i < sz; ++i)
            {
                node nb = adj[tmp.ver][i];
                if (tmp.weight + nb.weight < dist[nb.ver])
                {
                    dist[nb.ver] = tmp.weight + nb.weight;
                    nb.weight = dist[nb.ver];
                    q.push(nb);
                }
            }
        }
    }

    for (int i = 0; i < cnt; ++i)
        cout << dist[query[i]] << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();

    return 0;
}

/**
8 12
0 1 15
5 1 4
6 5 5
4 6 7
7 4 8
3 5 10
2 0 2
5 1 9
5 4 5
4 1 8
6 2 10
2 6 7
2
4 6
3
3
0
2

*/
