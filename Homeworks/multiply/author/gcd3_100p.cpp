#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cmath>

typedef long long llong;
const int MAXNUM = 10000000 + 10;
const int MAXN = 500000 + 10;
const int CNTPRIME = 665000;
const int INF = 1e9;

int n;
int a[MAXN];
int num[MAXNUM];
int lowestDiv[MAXNUM];
bool vis[MAXN + CNTPRIME];
std::vector <int> g[MAXN + CNTPRIME];
std::vector <int> primes;

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
    for (int i = 2 ; i < MAXNUM ; ++i)
    {
        if (lowestDiv[i] == 0)
        {
            lowestDiv[i] = i;
            primes.push_back(i);
            num[i] = primes.size();
        }

        for (int j = 0 ; i * primes[j] < MAXNUM ; ++j)
        {
            lowestDiv[i * primes[j]] = primes[j];
            if (primes[j] == lowestDiv[i]) break;
        }
    }

    for (int i = 1 ; i <= n ; ++i)
    {
        int last = 0;
        while (a[i] >= 2)
        {
            if (last != lowestDiv[a[i]])
            {
                g[primes.size() + i].push_back(num[lowestDiv[a[i]]]);
                g[num[lowestDiv[a[i]]]].push_back(primes.size() + i);
            }

            last = lowestDiv[a[i]];
            a[i] /= lowestDiv[a[i]];
        }
    }

    int ans = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        if (vis[primes.size() + i])
        {
            continue;
        }

        dfs(primes.size() + i);
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