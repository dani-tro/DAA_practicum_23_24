#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100100

long long n, a[MAX], k, maxcnt, currcnt;

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

    sort(a, a + n);
    for (int i = 0; i < n; ++i)
    {
        int j = i + currcnt - 1;
        if (currcnt > 0)
            --currcnt;
        while (j < n && a[j] - a[i] <= k)
        {
            ++j;
            ++currcnt;
        }
        if (maxcnt < currcnt)
            maxcnt = currcnt;
    }

    cout << maxcnt << endl;

    return 0;
}