#include <iostream>

using namespace std;

#define MAX 100100

int n, k;
long long a[MAX], maxd, mind;

long long possible(long long dist)
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
    if (curr > dist)
    {
        ++cnt;
    }
    return cnt;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    mind = 1000000000;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> a[i];
        if (mind > a[i])
            mind = a[i];
        if (maxd < a[i])
            maxd = a[i];
    }

    long long l = 0;
    long long r = maxd;

    while (l < r)
    {
        long long mid = (l + r) / 2;
        if (possible(mid) > k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }

    cout << l << endl;
    return 0;
}