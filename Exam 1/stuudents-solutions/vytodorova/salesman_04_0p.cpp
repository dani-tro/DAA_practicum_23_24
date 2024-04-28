#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void arrsort(vector<double>& arr, double n, vector<double>& ind) {

    for (double i = 0; i < n; i++)
    {
        double minel = 999999999;
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
    cin.tie(NULL);
    cout.tie(NULL);

    double m;
    cin >> m;

    vector<double> pr;
    vector<double> kg;
    vector<double> ind;   

    double n;
    cin >> n;
    for (double i = 0; i < n; i++)
    {
        double x;
        cin >> x;
        double y;
        cin >> y;
        kg.push_back(x);
        pr.push_back(y);
        ind.push_back(i);
    }

    arrsort(pr, n, ind);

    double sum = 0;

    vector<double> used;

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
    cout << fixed << setprecision(2) << sum << endl;

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