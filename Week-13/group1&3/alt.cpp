#include <bits/stdc++.h>

using namespace std;

#define MAXN 52

long long m, n, k, dp[2][MAXN];

int main()
{
    cin >> k >> m >> n;
    
    for(int i = 1; i < m; i++)dp[1][i] = 1;
    
    for(int i = 2; i <= n; i++)
    {
    	for(int j = 1; j < m; j++)
    	{
    		dp[i % 2][j] = 0;
    		if(j - k > 0)dp[i % 2][j] += dp[1 - i % 2][j - k];
			if(j + k < m)dp[i % 2][j] += dp[1 - i % 2][j + k]; 
		}
	}
	
	long long ans = 0;
	
	for(int i = 1; i < m; i++)ans += dp[n % 2][i];
	
	cout << ans << endl;
    
    return 0;
}

