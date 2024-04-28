#include <iostream>

using namespace std;

#define MAX 100100

int n, a[MAX], k, maxcnt, currcnt;

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
        int j = i;
        while (j < n && a[j] - a[i] <= k)
        {
            ++j;
            ++currcnt;
        }
        if (maxcnt < currcnt)
            maxcnt = currcnt;
        currcnt = 0;
    }

    cout << maxcnt << endl;

    return 0;
}