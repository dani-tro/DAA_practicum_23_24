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
    int count = 0;
    std::sort(atoms.begin(), atoms.end());
    for (int i = n - 1; i >= 0; i--)
    {
        long diff = atoms[n - 1] - atoms[i];
        if (diff <= k)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    input();
    std::cout << solve();
}