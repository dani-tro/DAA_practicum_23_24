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
    std::sort(atoms.begin(), atoms.end());
    int maxCount = 0;
    int l = 0;
    int r = 0;

    while (r < n)
    {
        while (atoms[r] - atoms[l] > k)
        {
            l++;
        }
        maxCount = std::max(maxCount, r - l + 1);
        r++;
    }
    return maxCount; 
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    input();
    std::cout << solve();
}