#include <iostream>
#include <vector>
#include <algorithm>

int n;
long k;
std::vector<long> atoms;

void input()
{
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        long num;
        std::cin >> num;
        atoms.push_back(num);
    }
}

int solve()
{
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (atoms[r] - atoms[mid] > k)
        {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return l + r; 
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    input();
    std::cout << solve();
}