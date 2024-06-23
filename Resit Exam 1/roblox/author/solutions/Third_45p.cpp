#include <iostream>
#define int long long
const int maxn = 10000000 + 10;

int a[maxn], n, k;

void solve()
{
    int ans = 0, sum = 0, res = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        sum = 0, res = 0;
        for (int j = i ; j <= n ; ++j)
        {
            res += a[j] * sum;
            sum += a[j];
            ans += (res >= k);
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