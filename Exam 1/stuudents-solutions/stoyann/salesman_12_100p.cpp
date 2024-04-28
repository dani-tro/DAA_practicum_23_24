#include <iostream>
#include <algorithm>
#include <iomanip>
// #include <bits/stdc++.h>

using namespace std;

#define MAX 128

struct product
{
    double kilo;
    double price;
    int idx;
};
int n;
product p[MAX];
double m, maxprice, kilos[MAX];

bool cmp(product a, product b)
{
    if (a.price == b.price)
        return a.kilo < b.kilo;
    return a.price < b.price;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> fixed >> setprecision(3) >> p[i].kilo;
        cin >> fixed >> setprecision(2) >> p[i].price;
        p[i].idx = i;
    }

    sort(p, p + n, cmp);

    int i = n - 1;
    while (i >= 0 && m > 0)
    {
        if (m >= p[i].kilo)
        {
            maxprice += p[i].kilo * p[i].price;
            kilos[p[i].idx] = p[i].kilo;
        }
        else
        {
            maxprice += m * p[i].price;
            kilos[p[i].idx] = m;
        }
        m -= p[i].kilo;
        --i;
    }

    cout << fixed << setprecision(2) << maxprice << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << fixed << setprecision(3) << kilos[i] << endl;
    }

    return 0;
}