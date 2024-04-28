#include <iostream>
#include <vector>
#include <algorithm>

long long n;
long long k;
std::vector<long long> vector;

bool valid(long long m)
{
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if(std::abs(vector[i + 1] - vector[i]) > k)
        {
            return false;
        }
    }
    return count <= k;
}

long long solve()
{
    int l = 0;
    int r = n;
    while(l <= r)
    {
        long long mid = l + (r - l) / 2;
        //std::cout << "mid:" << mid << '\n';
        if(valid(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return l;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> k;
    for (size_t i = 0; i < n; i++)
    {
        long long x;
        std::cin >> x;
        vector.push_back(x);
    }

    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if(std::abs(vector[i + 1] - vector[i]) <= k)
        {
            ++count;
            
        }
    }
    std::cout << count << std::endl;


    //std::sort(vector.begin(), vector.end());

    //std::cout << solve();
    
}

/*
10 4
5 9 3 1 2 7 8 9 5 8

*/