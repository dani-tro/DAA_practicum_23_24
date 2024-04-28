#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 100003
using namespace std;
typedef long long ll;
int n;
ll k;
ll arr[MAXN];

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
}

void solve()
{
    sort(arr, arr + n);
    int max1 = -1;
    for (int i = 0; i < n; ++i)
    {
        int l = i, r = n - 1, mid;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (arr[mid] - arr[i] <= k)
                l = mid + 1;
            else
                r = mid - 1;
        }

        max1 = max(max1, l - i);
    }

    cout << max1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();

    return 0;
}

/**

10 4
5 9 3 1 2 7 8 9 5 8

*/
