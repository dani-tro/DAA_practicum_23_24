#include <bits/stdc++.h>

using namespace std;

#define MAX 210000

long long n, k, a[MAX], b[MAX], ans, opt;

long long calc(int x)
{
    long long j = n - 1;
    long long cnt = 0;
    for(int i = 0; i < n; i++)
    {
        while(j >= 0 && a[i] + b[j] > x)
        {
            j--;
        }
        cnt += (j + 1);
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < n; i++)cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    long long l = 0, r = a[n - 1] + b[n - 1], mid;

    while(l <= r)
    {
        mid = (l + r) / 2;
        if(calc(mid) >= k)
        {
            opt = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << opt << endl;

    return 0;
}

