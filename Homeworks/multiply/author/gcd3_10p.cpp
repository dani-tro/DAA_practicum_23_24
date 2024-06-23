#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cmath>

typedef long long llong;
const int MAXNUM = 10000000 + 10;
const int MAXN = 100000 + 10;
const int INF  = 1e9;

int n;
int a[MAXN];
bool bl[MAXNUM];
void solve()
{
    int ans = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        ans += !bl[a[i]];
        bl[a[i]] = true;
    }

    std::cout << ans << '\n';
}

void input()
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
    input();
    solve();

    return 0;
}