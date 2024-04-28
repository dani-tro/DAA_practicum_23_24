#include <bits/stdc++.h>
using namespace std;

#define MAX 200010

int n, k;
int arr[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    int i;
    for (i = 0; i < n; ++i)
        cin >> arr[i];

    sort(arr, arr + n);

    int currMax = 1, maxOverall = 0, firstCrit = 0;

    for (i = 0; i < n; ++i)
    {
        if (currMax == 0)
        {
            i = ++firstCrit;
            currMax++;
        }

        if (arr[i] <= arr[firstCrit] + k)
        {
            currMax++;
        }
        else
        {
            maxOverall = max(maxOverall, currMax - 1);
            currMax = 0;
        }
    }

    cout << max(maxOverall, currMax - 1) << endl;
}