#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <vector>
#include <queue>

typedef long long llong;
const int MAXN = 300000 + 10;
const int MAXLOG = 19;
const int MOD = 998244353;
const int INF  = 1e9;

int n, m;
int base[MAXLOG];
struct Sparse
{
    int parent[MAXLOG][MAXN];
    int hash[MAXLOG][MAXN];

    void push(int node, int par, char c)
    {
        parent[0][node] = par;
        hash[0][node] = c - 'a' + 1;

        for (int lg = 1 ; (1 << lg) <= n ; ++lg)
        {
            parent[lg][node] = parent[lg - 1][parent[lg - 1][node]];
            hash[lg][node] = (1LL * base[lg] * hash[lg - 1][node] + hash[lg - 1][parent[lg - 1][node]]) % MOD;
        }
    }

    int getHash(int node)
    {
        int res = 0;
        for (int lg = MAXLOG - 1 ; lg >= 0 ; --lg)
        {
            if (parent[lg][node] == 0)
            {
                continue;
            }

            res = (1LL * base[lg] * res + hash[lg][node]) % MOD;
            node = parent[lg][node];
        }

        return res;
    }

    int getParent(int node, int k)
    {
        for (int lg = MAXLOG - 1 ; lg >= 0 ; --lg)
        {
            if (k & (1 << lg))
            {
                node = parent[lg][node];
            }
        }

        return node;
    }

    bool cmp(int u, char letterU, int v, char letterV, int d)
    {
        int l = -1, r = d + 1, mid;
        while (l < r - 1)
        {
            mid = (l + r) / 2;
            if (getHash(getParent(u, mid)) != getHash(getParent(v, mid))) l = mid;
            else r = mid;
        }

        if (r == 0)
        {
            return letterU < letterV;
        }

        return hash[0][getParent(u, l)] < hash[0][getParent(v, l)];
    }
};

int dist[MAXN];
int parent[MAXN];
char parentLetter[MAXN];
std::vector <std::pair <int,char>> g[MAXN];
Sparse sparse;
int cnt;

void solve()
{
    base[0] = 27;
    for (int lg = 1 ; (1 << lg) <= n ; ++lg)
    {
        base[lg] = (1LL * base[lg - 1] * base[lg - 1]) % MOD;
    }

    std::fill(dist + 1, dist + 1 + n, INF);
    std::queue <int> q; 
    dist[1] = 0;
    q.push(1);

    int last = -1;
    while (q.size())
    {
        int node = q.front();
        q.pop();

        sparse.push(node, parent[node], parentLetter[node]);
        for (const auto &[u, c] : g[node])
        {
            if (dist[u] == INF || (dist[u] == dist[node] + 1 && sparse.cmp(node, c, parent[u], parentLetter[u], dist[node])))
            {
                parent[u] = node;
                parentLetter[u] = c;
                if (dist[u] == INF)
                {
                    q.push(u);
                    dist[u] = dist[node] + 1;
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