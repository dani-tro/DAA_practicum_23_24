#include <bits/stdc++.h>

using namespace std;

#define MAX 61000

long long n, x[MAX], v[MAX];

double calc(double m)
{
    double mx = 0;
    for(int i = 0; i < n; i++)
    {
        mx = max(mx, fabs(m - x[i]) / v[i]);
    }
    return mx;
}

int main()
{

    cin >> n;
    for(int i = 0; i < n; i++)cin >> x[i];
    for(int i = 0; i < n; i++)cin >> v[i];
    double l = 0, r = 1e9, m1, m2, c1, c2;

    for(int i = 0; i < 128; i++)
    {
        m1 = l + (r - l) * (1.0 / 3);
        m2 = l + (r - l) * (2.0 / 3);
        c1 = calc(m1);
        c2 = calc(m2);
        if(c1 > c2)
        {
            l = m1;
        }
        else
        {
            r = m2;
        }
    }
    cout << fixed << setprecision(10) << calc(l) << endl;

    return 0;
}
