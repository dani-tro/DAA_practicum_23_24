#include <bits/stdc++.h>
using namespace std;

// #define MAXN 10007
// #define MAXK 1007

long long n, k, a[10007], m[1007], ans, dp[10007][1007], l1, r1;

long long calc(long long l, long long r)
{
    if (dp[l][r] == -1)
    {
        // if (l + 1 >= r)
        // {
        //     dp[l][r] = 0;
        //     return 0;
        // }

        dp[l][r] = 0;

        for (int i = 1; i <= k; i++)
        {
            l1 = l + m[i];

            if (l1 < r && l1 >= 1)
            {
                dp[l][r] = max(dp[l][r], a[l1] + calc(l1, r));
            }    
        }
        
        for (long long i = 1; i <= k; i++)
        {
            r1 = r - m[i];

            if (r1 > l && r1 <= n)
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
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (long long i = 1; i <= k; i++)
    {
        cin >> m[i];
    }

    for (long long i = 0; i <= n + 1; i++)
    {
        fill(dp[i], dp[i] + n + 1, -1);
    }

    ans = calc(1, n) + a[1] + a[n];
    cout << ans << endl;
    
    return 0;
}