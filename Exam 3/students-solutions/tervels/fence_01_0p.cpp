#include <iostream>

using namespace std;
const int MAXN = 1e4 + 5, MAXK = 1e3+5;
long long int n, k, a[MAXN], steps[MAXK], dp[MAXN][MAXN];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= k; ++i)
        cin >> steps[i];

    for (int i = 1; i < n; ++i)
        dp[i][i+1] = a[i] + a[i + 1];

    for (int i = 1; i < n - 1; ++i)
    {
        for (int j = i + 2; j <= n; ++j)
        {
            long long ans = 0, s = a[i] + a[j];

            for (int p = 1; p <= k; ++p)
            {
                ans = max((i + steps[p] < j ? dp[i+steps[p]][j] : 0),(j - steps[p] > i ? dp[i][j-steps[p]] : 0));
                s = max(s, s + ans);
                // curr_max = max(curr_max,
                //     max(s + (i + steps[p] < j ? dp[i+steps[p]][j] : 0),
                //         s + (j - steps[p] > i ? dp[i][j-steps[p]] : 0)));
            }

            dp[i][j] = s;
        }
    }

    cout << dp[1][n] << endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << dp[i][j] << ' ';
        cout << endl;
    }
    return 0;
}