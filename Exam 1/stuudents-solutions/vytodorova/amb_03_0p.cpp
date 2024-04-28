#include <iostream>
#include <queue>
#include <algorithm>

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::deque<long long> dq;
    long long n;
    long long k;
    std::cin >> n;
    std::cin >> k;
    for (long long i = 0; i < n-1; i++)
    {
        long long x;
        std::cin >> x;
        dq.push_back(x);
    }

    std::cout << 0;

}