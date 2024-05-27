#include <bits/stdc++.h>

using namespace std;

#define MAXK 52

#define MAXN 52

long long n, k, dp[MAXK][MAXN];

int main()
{
    cin >> k >> n;
    
    for(int i = 0; i <= k; i++)dp[i][0] = 1;
    
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    
    cout << dp[k][n] << endl;
    
    return 0;
}

