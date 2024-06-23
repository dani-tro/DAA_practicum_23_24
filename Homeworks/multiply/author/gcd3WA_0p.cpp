#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <bitset>
#include <vector>
#include <cmath>

typedef long long llong;
const int MAXNUM = 10000000 + 10;
const int MAXN = 100 + 10;
const int CNTPRIME = 665000;
const int INF = 1e9;

int n;
int a[MAXN];
bool vis[MAXN];
int num[MAXNUM];
bool isActive[MAXN];
int lowestDiv[MAXNUM];
std::vector <int> primes;
std::bitset <CNTPRIME> bs[MAXN];

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
                bs[i][num[lowestDiv[a[i]]]] = 1;
            }

            last = lowestDiv[a[i]];
            a[i] /= lowestDiv[a[i]];
        }
    }

    int ans = n;
    for (int i = 1 ; i <= n ; ++i)
    {
        if (vis[i])
        {
            continue;
        }
        
        for (int j = i + 1 ; j <= n ; ++j)
        {
            if (vis[j] || i == j)
            {
                continue;
            }

            if ((bs[i] & bs[j]).count())
            {
                bs[i] |= bs[j];
                vis[j] = true;
                ans--;
            }
        }
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