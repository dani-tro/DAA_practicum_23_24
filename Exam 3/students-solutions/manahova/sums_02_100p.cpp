#include <bits/stdc++.h>
using namespace std;

#define MAX 105

int a, b, n, arr[MAX];
long long dp[MAX][MAX], ans;

long long calc(int s, int m)
{
    if (s <= 0) return 0;

    if (dp[s][m] == -1)
    {
        if (m == 1)
        {
            if (arr[1] == s)
            {
                dp[s][m] = 1;
            }
            else
            {
                dp[s][m] = 0;
            }
        }
        else
        {
            dp[s][m] = calc(s, m - 1) + calc(s - arr[m], m - 1);
            if (arr[m] == s)
            {
                dp[s][m]++;
            }
        }
    }

    return dp[s][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> a >> b;

    for (int i = 1; i <= b; i++)
    {
        fill(dp[i], dp[i] + n + 1, -1);
    }
    

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = a; i <= b; i++)
    {
        if (calc(i, n))
        {
            ans++;
        }
    }
    
    cout << ans << endl;

    return 0;
}