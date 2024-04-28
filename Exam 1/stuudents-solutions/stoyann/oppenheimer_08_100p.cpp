#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100100

long long n, a[MAX], k, maxcnt, currcnt = 1;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int j = 1;
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
    {
        while (j < n && a[j] - a[i] <= k)
        {
            ++j;
            ++currcnt;
        }
        if (maxcnt < currcnt)
            maxcnt = currcnt;
        --currcnt;
    }

    cout << maxcnt << endl;

    return 0;
}