#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cmath>

typedef long long llong;
const int MAXN = 100000 + 10;
const int INF  = 1e9;

int n;
int a[MAXN];
bool vis[MAXN];
std::vector <int> g[MAXN];
void dfs(int node)
{
    vis[node] = true;
    for (const int &i : g[node])
    {
        if (vis[i]) continue;
        dfs(i);
    }
}

void solve()
{
    for (int i = 1 ; i <= n ; ++i)
    {
        for (int j = i + 1 ; j <= n ; ++j)
        {
            if (std::__gcd(a[i], a[j]) == 1) continue;
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }

    
    int ans = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        if (vis[i])
        {
            continue;
        }

        dfs(i);
        ans++;
    }

    std::cout << ans << '\n';
}

void read()
{
    std::cin >> n;
    for (int i = 1 ; i <= n ; ++i)
    {
        std::cin >> a[i];
    }
}

void fastIO()
{
    std::ios_base :: sync_with_stdio(0);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
}

int main()
{
    fastIO();
    read();
    solve();

    return 0;
}