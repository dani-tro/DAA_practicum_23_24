#include <bits/stdc++.h>

using namespace std;

#define eps 1e-14

double x, l, r, mid;

int main()
{

    cin >> x;
    r = max(double(1), x);

    for(int i = 0; i < 100; i++)
    {
        mid = (l + r) / 2;
        if(mid * mid * mid >= x)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << setprecision(20) << l << endl;
    return 0;
}
