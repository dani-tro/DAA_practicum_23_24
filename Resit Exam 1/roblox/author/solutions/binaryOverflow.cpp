#include <iostream>

typedef long long llong;
const int maxn = 10000000 + 10;

llong a[maxn], n, k;
llong prefix[maxn], prefixSquared[maxn];

inline llong calcSum(int l, int r)
{
    --l;
    llong sum = (prefix[r] - prefix[l]);
    llong sum2 = (prefixSquared[r] - prefixSquared[l]);
    if (sum >= (2*k + sum2) / sum + 2) return k+1;
    return (sum*sum - sum2) / 2;
}

void solve()
{
    for (int i = 1 ; i <= n ; ++i)
    {
        prefix[i] = prefix[i-1] + a[i];
        prefixSquared[i] = prefixSquared[i-1] + a[i] * a[i];
    }

    llong ans = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        int l = 0, r = i+1, mid;
        while (l < r - 1)
        {
            mid = (l + r) / 2;
            if (calcSum(mid, i) >= k) l = mid;
            else r = mid;
        }

        ans += l;
    }

    std::cout << ans << '\n';
}

void read()
{
    std::cin >> n >> k;
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