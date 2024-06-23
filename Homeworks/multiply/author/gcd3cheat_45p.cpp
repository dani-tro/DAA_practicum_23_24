#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <cassert>
#include <bitset>
#include <vector>
#include <cmath>

typedef long long llong;
const int MAXNUM = 10000000 + 10;
const int MAXN = 2500 + 10;
const int CNTPRIME = 2500;
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
        }

        for (int j = 0 ; i * primes[j] < MAXNUM ; ++j)
        {
            lowestDiv[i * primes[j]] = primes[j];
            if (primes[j] == lowestDiv[i]) break;
        }
    }

    int cnt = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        int last = 0;
        while (a[i] >= 2)
        {
            if (last != lowestDiv[a[i]])
            {
                if (num[lowestDiv[a[i]]] == 0) num[lowestDiv[a[i]]] = ++cnt; 
                assert(cnt < MAXNUM);
                bs[i][num[lowestDiv[a[i]]]] = 1;
            }

            last = lowestDiv[a[i]];
            a[i] /= lowestDiv[a[i]];
        }
    }

    int ans = n;
    for (int i = 1 ; i <= n ; ++i)
    {
        for (int j = i + 1 ; j <= n ; ++j)
        {
            if ((bs[i] & bs[j]).count())
            {
                bs[j] |= bs[i];
                ans -= !vis[i];
                vis[i] = true;
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