#include <bits/stdc++.h>
using namespace std;

#define MAX 105

int a, b, n, arr[MAX];
long long dp[MAX][MAX], ans;

// long long calc(int l, int h, int m)
// {
//     if (h < 0) return 0;
//     if (l < 0) l = 0;

//     if (dp[l][h][m] == 0)
//     {
//         if (m == 1) 
//         {
//             if (arr[m] >= l && arr[m] <= h)
//             {
//                 dp[l][h][1] = 1;
//             }
//             else
//             {
//                 dp[l][h][1] = 0;
//             }
//         }
        
//         else
//         {
//             dp[l][h][m] = calc(l, h, m - 1) + calc(l - arr[m], h - arr[m], m - 1);

//             if (arr[m] >= l && arr[m] <= h)
//             {
//                 dp[l][h][m]++;
//             }
//         }   
//     }
    
//     cout << "dp[" << l << "][" << h << "][" << m << "] = " << dp[l][h][m] << endl;
//     return dp[l][h][m];
// }

long long calc(int s, int m)
{
    if (s <= 0) return 0;

    if (dp[s][m] == 0)
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