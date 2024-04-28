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
    for (long long i = 0; i < n; i++)
    {
        long long x;
        std::cin >> x;
        dq.push_back(x);
    }
    long long maxc = 0;
    long long l = 0;
    long long r = n-1;
    long long count;

    std::sort(dq.begin(),dq.end());

    for (long long i = 0; i < n; i++)
    {
        count = 0;
        for (long long j = i; j < n; j++)
        {
            if (dq.at(j) - dq.at(i) <= k)
                count++;
        }
        if (count > maxc)
            maxc = count;
    }
    
    std::cout << maxc;
    
}