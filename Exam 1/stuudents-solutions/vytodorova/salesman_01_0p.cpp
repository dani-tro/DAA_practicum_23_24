#include <iostream>
#include <vector>
#include <algorithm>

// 2 3 1 5 4
// 1 2 3 4 5
// 2 0 1 4 3


void arrsort(std::vector<double>& arr, double n, std::vector<double>& ind) {

    for (double i = 0; i < n; i++)
    {
        double minel = 9999999;
        double minind = 0;
        for (double j = i; j < n; j++)
        {
            if (arr[j] <= minel)
            {
                minel = arr[j];
                minind = j;
            }
        }

        double x = arr[i];
        arr[i] = minel;
        arr[minind] = x;

        double y = ind[i];
        ind[i] = ind[minind];
        ind[minind] = y;

    }
    
}


int main()
{
    double m;
    std::cin >> m;

    std::vector<double> pr;
    std::vector<double> kg;
    std::vector<double> ind;   

    double n;
    std::cin >> n;
    for (double i = 0; i < n; i++)
    {
        double x;
        std::cin >> x;
        double y;
        std::cin >> y;
        kg.push_back(x);
        pr.push_back(y);
        ind.push_back(i);
    }

    arrsort(pr, n, ind);

    double sum = 0;

    for (double i = 0; i < n; i++)
    {
        if (kg[ind[n - 1 - i]] <= m)
        {
            sum += kg[ind[n - 1 - i]] * pr[n - i - 1];
            m -= kg[n - 1 - i];
        }
        else 
        {
            sum += m * pr[n - i - 1];
            break;
        }
    }

    std::cout << sum;

    

}