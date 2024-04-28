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
    std::vector<long long> dq2;

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
        dq2.push_back(x);
    }

    long long maxel = 0;
    long long pos = 0;

    for (long long i = 0; i < n; i++)
    {
        if (dq2.at(i) > maxel)
        {
            maxel = dq2.at(i);
            pos = i;
        }     
    }
    dq2[pos] = -1;

    long long maxel2 = 0;

    long long pos2 = 0;

    for (long long i = 0; i < n; i++)
    {
        if (dq2.at(i) > maxel2)
        {
            maxel2 = dq2.at(i);
            pos2 = i;
        }
    }

    if (pos == 0)
    {
        if (k > 0)
            k--;
        dq[0] = 0;
    }
    else if (pos == n - 1) 
    {
        if (k > 0)
            k--;
        dq[n-1] = 0;
    }

    if (pos2 == 0)
    {
        if (k > 0)
            k--;
        dq[0] = 0;
    }
    else if (pos2 == n - 1)
    {
        if (k > 0)
            k--;
        dq[n - 1] = 0;
    }

    std::sort(dq.begin(), dq.end());
    std::cout << dq[n - 1 - k];

}