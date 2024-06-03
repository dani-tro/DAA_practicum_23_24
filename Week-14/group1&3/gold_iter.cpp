#include <bits/stdc++.h>

using namespace std;

#define MAXN 52

#define MAXSUM 50100

int n, a[MAXN], dp[MAXN][MAXSUM];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        fill(dp[i], dp[i] + MAXSUM, INT_MAX / 2);
    }
    
    
    dp[1][a[1]] = 0;
    dp[1][0] = a[1];
    
    for(int i = 2; i <= n; i++)
    {
    	for(int j = 0; j < MAXSUM; j++)
    	{
    		dp[i][j] = min(dp[i][j], dp[i - 1][abs(j - a[i])]);
    		dp[i][j] = min(dp[i][j], dp[i - 1][j + a[i]]);
    		dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i]);
		}
	}

    cout << dp[n][0] << endl;
    return 0;
}

