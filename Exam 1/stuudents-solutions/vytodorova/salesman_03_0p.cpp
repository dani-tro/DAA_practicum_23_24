#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

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

    std::vector<double> used;

    for (double i = 0; i < n; i++)
    {
        if (kg[ind[n - 1 - i]] <= m)
        {
            sum += kg[ind[n - 1 - i]] * pr[n - i - 1];
            m -= kg[ind[n - 1 - i]];
            used.push_back(kg[ind[n - 1 - i]]);
        }
        else 
        {
            sum += m * pr[n - i - 1];
            used.push_back(m);
            break;
        }
    }
    cout << fixed << setprecision(2) << sum << std::endl;

    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            cout << fixed << setprecision(3) << used[i] << endl;
        }
        else
        {
            cout << fixed << setprecision(3) << used[i];
        }
    }


}