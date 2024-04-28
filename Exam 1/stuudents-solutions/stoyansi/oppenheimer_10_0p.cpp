#include <iostream>
#include <vector>
#include <algorithm>

long long n;
long long k;
std::vector<long long> vector;

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
        //std::cout << x << i << '\n';
    }

    long long count = 0;
    long long l = 0;
    long long r = n - 1;

    std::sort(vector.begin(), vector.end());

    while(l <= r)
    {
        if(vector[r] - vector[l] > k)
        {
            ++l;
            --r;
            ++count;
        }
        else
        {
            break;
        }
    }
    std::cout << (n - count);
}

/*
10 4
5 9 3 1 2 7 8 9 5 8

*/