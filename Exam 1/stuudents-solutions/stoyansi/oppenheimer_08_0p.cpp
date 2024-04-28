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
    long long slow = 1;
    long long fast = 0;

    while(slow != n)
    {
        if(vector[fast] - vector[slow] > k)
        {
            ++slow;
            count++;
            //std::cout << "vector[slow]: " << vector[slow] << " vector[fast]: " << vector[fast] << '\n';
        }
        else
        {
            ++fast;
            ++slow;
        }
    }
    std::cout << (n - count);
}

/*
10 4
5 9 3 1 2 7 8 9 5 8

*/