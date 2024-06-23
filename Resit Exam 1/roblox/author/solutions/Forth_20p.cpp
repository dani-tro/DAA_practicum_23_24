#include <iostream>

typedef long long llong;
const int maxn = 10000000 + 10;

llong a[maxn], n, k;
void solve()
{
    llong ans = 0, last = 0, last1 = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        if (a[i] != 0) 
        {
            last = last1;
            last1 = i;
        }

        ans += (i - last - 1);
    }

    std::cout << n*(n-1)/2 - ans << '\n';
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