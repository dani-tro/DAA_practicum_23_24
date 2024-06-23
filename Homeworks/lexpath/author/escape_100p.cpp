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
int parent[MAXN];
int trieNumber[MAXN];
char parentLetter[MAXN];
std::vector <std::pair <int,char>> g[MAXN];
std::vector <int> nodes[MAXN];
int cnt;

bool cmp(int x, int y)
{
    if (trieNumber[parent[x]] != trieNumber[parent[y]]) return trieNumber[parent[x]] < trieNumber[parent[y]];
    if (parentLetter[x] != parentLetter[y]) return parentLetter[x] < parentLetter[y];
    return false;
}

void solve()
{
    std::fill(dist + 1, dist + 1 + n, INF);
    std::queue <int> q; 
    nodes[0].push_back(1);
    dist[1] = 0;
    q.push(1);

    int last = -1;
    while (q.size())
    {
        int node = q.front();
        q.pop();

        if (dist[node] != last)
        {
            std::sort(nodes[dist[node]].begin(), nodes[dist[node]].end(), cmp);
            trieNumber[nodes[dist[node]][0]] = ++cnt;
            for (int i = 1 ; i < nodes[dist[node]].size() ; ++i)
            {
                if (cmp(nodes[dist[node]][i - 1], nodes[dist[node]][i]))
                {
                    cnt++;
                }

                trieNumber[nodes[dist[node]][i]] = cnt;
            }

            last++;
        }

        for (const auto &[u, c] : g[node])
        {
            if (dist[u] == INF || (dist[u] == dist[node] + 1 && (trieNumber[node] < trieNumber[parent[u]] || (trieNumber[node] == trieNumber[parent[u]] && c < parentLetter[u]))))
            {
                parent[u] = node;
                parentLetter[u] = c;
                if (dist[u] == INF)
                {
                    q.push(u);
                    dist[u] = dist[node] + 1;
                    nodes[dist[u]].push_back(u);
                }

            }
        }
    }

    int node = n;
    std::string answer;
    while (node != 1)
    {
        answer += parentLetter[node];
        node = parent[node];
    }

    std::reverse(answer.begin(), answer.end());
    std::cout << answer << '\n';
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