#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>

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
        int a;
        std::cin >> a;
        chisla.push_back(a);
    }

    std::sort(chisla.begin(), chisla.end());

    std::vector<long long> dif;
    for (size_t i = 0; i < n-1; i++)
    {
        int rz = abs(chisla[i] - chisla[i + 1]);
        dif.push_back(rz);
    }

    /*for (size_t i = 0; i < dif.size(); i++)
    {
        std::cout << dif[i] << " ";
    }*/

    long long maxSum = 0;
    long long currSum = 0;
    int countMax = 0;
    int countCurr = 0;
    long long size = dif.size();

    for (size_t i = 0; i < size; i++)
    {
        if (currSum + dif[i] <= k)
        {
            currSum += dif[i];
            countCurr++;
        }
        else
        {
            if (currSum > maxSum)
            {
                maxSum = currSum;
                countMax = countCurr;
            }
            if (dif[i] <= k)
            {
                currSum = dif[i];
                countCurr = 1;
            }
            else
            {
                currSum = 0;
                countCurr = 0;
            }
        }

    }

    std::cout << countMax + 1;
  
}