#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double m;
int n;

struct Stock
{
    double quantity, price;
    int idx;

    bool operator < (const Stock& other) const
    {
        return this->price > other.price;
    }
};
Stock stocks[128];
double taken[128];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> stocks[i].quantity >> stocks[i].price;
        stocks[i].idx = i;
    }
    std::sort(stocks, stocks + n);

    int i = 0;
    double price = 0;
    while (m >= 0 && i < n)
    {
        if (m - stocks[i].quantity >= 0)
        {
            taken[stocks[i].idx] = stocks[i].quantity;
            price += stocks[i].quantity * stocks[i].price;
            m -= stocks[i].quantity;
        }
        else
        {
            taken[stocks[i].idx] = m;
             price += m * stocks[i].price;
            m = -5;
        }
        ++i;
    }

    cout << fixed << setprecision(2) << price << endl;
    for (int i = 0; i < n; ++i)
        cout << fixed << setprecision(3) << taken[i] << endl;
    
    return 0;
}