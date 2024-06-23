#include <iostream>

typedef long long llong;
const int maxn = 10000000 + 10;

llong a[maxn], n, k;
llong currentSum;
llong pairwiseSum;

void solve()
{
    int l = 0;
    llong ans = 0;
    for (int r = 1 ; r <= n ; ++r)
    {
        pairwiseSum += currentSum * a[r];
        currentSum += a[r];
        while (pairwiseSum - (currentSum - a[l]) * a[l] >= k)
        {
            pairwiseSum -= (currentSum - a[l]) * a[l];
            currentSum -= a[l];
            ++l;
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