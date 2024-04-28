#include <bits/stdc++.h>
using namespace std;

#define MAX 100010

int n, k;
long long normArr[MAX];
long long arr[MAX];
bool tvs[MAX]{false};

int binarySearch(int l, int r, long long target)
{
    if (r <= l)
    {
        if (tvs[l])
        {
            return l + 1;
        }
        return l;
    }

    int m = l + (r - l) / 2;

    if (arr[m] > target)
    {
        return binarySearch(l, m, target);
    }
    else
    {
        return binarySearch(m + 1, r, target);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    int i, prev = 0;
    for (i = 0; i < n - 1; ++i)
    {
        cin >> normArr[i];
        arr[i] = normArr[i] + prev;
        prev = arr[i];
    }

    arr[n - 2] = normArr[n - 2] + prev;

    int magicValue = arr[n - 2] / (k + 1);
    // cout << magicValue << endl;

    int res;
    for (i = 1; i <= k; ++i)
    {
        res = binarySearch(0, n - 1, magicValue * i);
        // cout << res << ' ' << magicValue * i << endl;
        if (!tvs[res])
        {
            tvs[res] = true;
        }
        else
        {
            while (tvs[res])
            {
                res--;
            }
            tvs[res] = true;
        }
    }

    // for (i = 0; i < n; ++i)
    //     cout << tvs[i] << ' ';

    // cout << endl;

    int currMax = 0, maxOverall = 0;
    for (i = 0; i <= n; ++i)
    {
        if (tvs[i])
        {
            maxOverall = max(currMax, maxOverall);
            currMax = 0;
        }
        else
        {
            currMax += normArr[i];
        }

        // cout << currMax << ' ' << maxOverall << ' ' << endl;
    }

    // maxOverall = max(currMax, maxOverall);

    // for (i = n; i >= 0; --i)
    // {
    //     if (tvs[i])
    //     {
    //         maxOverall = max(currMax, maxOverall);
    //         currMax = 0;
    //     }
    //     else
    //     {
    //         currMax += normArr[i];
    //     }
    // }

    cout << max(currMax, maxOverall) << endl;
}