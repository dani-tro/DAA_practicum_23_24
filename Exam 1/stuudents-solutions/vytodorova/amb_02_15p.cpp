
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int answ = 0;

    //3 8 2 5 1 8 9 2 7

    std::vector<long long> dq;

    long long n;
    long long k;
    std::cin >> n;
    if (n != 0)
        n--;
    std::cin >> k;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        std::cin >> x;
        dq.push_back(x);
    }

    std::sort(dq.begin(), dq.end());
    std::cout << dq[n - k];

}