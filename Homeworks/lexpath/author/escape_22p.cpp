#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <vector>
#include <queue>

typedef long long llong;
const int MAXN = 300000 + 10;
const int INF  = 1e9;

int n, m;
int dist[MAXN];
std::string s[MAXN];
std::vector <std::pair <int,char>> g[MAXN];

void solve()
{
    std::fill(dist + 1, dist + 1 + n, INF);
    std::queue <int> q; 
    dist[1] = 0;
    q.push(1);

    while (q.size())
    {
        int node = q.front();
        q.pop();

        for (const auto &[u, c] : g[node])
        {
            if (dist[u] == INF || (dist[u] == dist[node] + 1 && s[u] > s[node] + c))
            {
                if (dist[u] == INF)
                {
                    q.push(u);
                }

                s[u] = s[node] + c;
                dist[u] = dist[node] + 1;
            }
        }
    }

    std::cout << s[n] << '\n';
}

void input()
{
    std::cin >> n >> m;
    for (int i = 1 ; i <= m ; ++i)
    {
        int u, v;
        char c;
        std::cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
}

void fastIOI()
{
    std::ios_base :: sync_with_stdio(0);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
}

int main()
{
    fastIOI();
    input();
    solve();

    return 0;
}