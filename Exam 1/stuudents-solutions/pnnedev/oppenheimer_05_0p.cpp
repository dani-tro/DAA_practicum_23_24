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
    long long size = dif.size();
    
    for (size_t i = 0; i < size-1; i++)
    {
        dif[i + 1] += dif[i];

    }

    int l = 0;
    int h = size - 1;
    long long maxRange = 0;;
    while (l < h)
    {
        long long rz = abs(dif[l] - dif[h]);

        if (rz > k)
        {
            if (abs(dif[l] - dif[l + 1]) < abs(dif[h] - dif[h - 1]))
            {
                    h--;
                
            }
            else
            {
                    l++;
            }
           // l++;

        }
        else
        {
            if (h - l + 1 > maxRange)
            {
                maxRange = (h - l) + 1;
            }
            break;
            h--;
        }
    }

    std::cout << maxRange;



}