#include <iostream>
#include <vector>
#include <algorithm>

int n;
long k;
std::vector<long> atoms;
int count = 0;

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

bool OK(int mid, int r)
{
    if (r - mid > k)
    {
        return false;
    }
    
    count++;
    return true;
}

int solve()
{
    int l = 0;
    int r = n - 1;

    std::sort(atoms.begin(), atoms.end());
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (OK(mid, r))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
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