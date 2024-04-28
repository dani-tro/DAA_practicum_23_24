#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

#define MAX 100100

int n, k;
long long a[MAX], sum;

bool possible(long long dist)
{
    long long cnt = 0;
    long long curr = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        curr += a[i];
        if (curr > dist)
        {
            ++cnt;
            curr = a[i];
        }
    }
    if (a[n - 2] > dist)
    {
        ++cnt;
    }
    return cnt <= k;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> a[i];
        sum += a[i] / 3;
    }

    long long l = 0;
    long long r = 1e18;
    // cout << r << endl;

    while (l < r)
    {
        long long mid = (l + r) / 2;
        if (!possible(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }

    cout << l << endl;
    // cout << possible(5) << endl;
    return 0;
}