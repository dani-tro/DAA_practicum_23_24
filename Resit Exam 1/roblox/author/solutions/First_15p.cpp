#include <iostream>

typedef long long llong;
const int maxn = 100000 + 10;

int a[maxn], n, k;

llong calc(int l, int r)
{
    llong res = 0;
    for (int i = l ; i <= r ; ++i)
    {
        for (int j = i+1 ; j <= r ; ++j)
        {
            res += a[i] * a[j];
        }
    }

    return res;
}

void solve()
{
    llong ans = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        for (int j = i ; j <= n ; ++j)
        {
            ans += (calc(i, j) >= k);
        }
    }

    std::cout << ans << '\n';
}

void read()
{
    std::cin >> n >> k;
    for (int i = 1 ; i <= n ; ++i) std::cin >> a[i];
}  

void fastIO()
{
    std::ios_base :: sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

signed main()
{
    fastIO();
    read();
    solve();

    return 0;
}