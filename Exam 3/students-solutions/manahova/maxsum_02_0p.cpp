#include <bits/stdc++.h>
using namespace std;

#define MAXN 100007
#define MAXK 1007

int n, k, a[MAXN], m[MAXK], ans, dp[MAXN][MAXN], l1, r1;

int calc(int l, int r)
{
    if (dp[l][r] == -1)
    {
        if (l + 1 >= r)
        {
            dp[l][r] = 0;
            return 0;
        }

        dp[l][r] = 0;

        for (int i = 1; i <= k; i++)
        {
            l1 = l + m[i];

            if (l1 < r)
            {
                dp[l][r] = max(dp[l][r], a[l1] + calc(l1, r));
            }    
        }
        
        for (int i = 1; i <= k; i++)
        {
            r1 = r - m[i];

            if (r1 > l)
            {
                dp[l][r] = max(dp[l][r], a[r1] + calc(l, r1));
            }
            
        }
    }

    //cout << "dp[" << l << "][" << r << "] = " << dp[l][r] << endl;
    return dp[l][r];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> m[i];
    }

    for (int i = 0; i <= n + 1; i++)
    {
        fill(dp[i], dp[i] + n + 1, -1);
    }

    ans = calc(1, n) + a[1] + a[n];
    cout << ans << endl;
    
    return 0;
}