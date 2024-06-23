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
std::vector <llong> s;
void solve()
{
    while (true)
    {
        bool bl = false;
        for (int i = 0 ; i < s.size() ; ++i)
        {
            for (int j = i + 1 ; j < s.size() ; ++j)
            {
                if (std::__gcd(s[i], s[j]) != 1)
                {
                    llong x = s[i];
                    llong y = s[j];
                    std::swap(s[j], s[s.size() - 1]);
                    std::swap(s[i], s[s.size() - 2]);
                    s.pop_back();
                    s.pop_back();
                    s.push_back(x * y);
                    bl = true;
                }
            }
        }

        if (!bl)
        {
            break;
        }
    }

    std::cout << s.size() << '\n';
}

void read()
{
    std::cin >> n;
    s.resize(n);

    for (int i = 0 ; i < n ; ++i)
    {
        std::cin >> s[i];
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