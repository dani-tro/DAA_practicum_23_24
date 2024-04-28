#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>
//#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<long long> chisla;
    long long n, k;
    std::cin >> n >> k;
    for (size_t i = 0; i < n; i++)
    {
        long long a;
        std::cin >> a;
        chisla.push_back(a);
    }

    std::sort(chisla.begin(), chisla.end());

    std::vector<long long> kur;
    for (size_t i = 0; i < n-1; i++)
    {
        long long rz = abs(chisla[i] - chisla[i + 1]);
        kur.push_back(rz);
    }
    long long size = chisla.size()-1;
    std::vector<long long> dif;
    dif.push_back(kur[0]);
    for (size_t i = 0; i < size-1; i++)
    {
        dif.push_back(kur[i + 1] + dif[i]);

    }

    long long l = 0;
    long long h = size - 1;
    long long maxRange = 0;
    while (l<h)
    {
        int tempH = h;
        while (l < tempH)
        {
            long long rz = abs(dif[l] - dif[tempH]);

            if (rz > k)
            {
                tempH--;
            }
            else
            {
                if (tempH - l + 1 > maxRange)
                {
                    maxRange = (tempH - l) + 1;
                }
                break;
            }
        }
        l++;

    }

    std::cout << maxRange;



}
    