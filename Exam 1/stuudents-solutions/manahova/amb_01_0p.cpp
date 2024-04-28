#include <bits/stdc++.h>
using namespace std;

#define MAX 101000

long long n, k, d[MAX];

bool possible(long long x)
{
    long long kcounter = 0;
    long long idx = 0;

    for (int i = 1; i <= n; i++)
    {
        if (d[i] - d[idx] <= x)
        {
            continue;
        }
        else
        {
            kcounter++;
            idx = i - 1;
            if (kcounter > k) return false;     
        }
    }
    return true;   
}

int main()
{  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long dist;

    cin >> n >> k;
    d[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        cin >> dist;
        d[i] = d[i-1] + dist;
    }

    long long l = 0, r = d[n];
    long long mid = (l + r) / 2;

    while (l < r)
    {
        mid = (l + r) / 2;

        if (possible(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << l << endl;

    return 0;
}