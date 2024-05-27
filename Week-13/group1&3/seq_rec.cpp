#include <bits/stdc++.h>

using namespace std;

#define MAXK 52

#define MAXN 52

long long n, k, dp[MAXK][MAXN];

long long calc(int k, int n)
{
	if(n == 0)return 1;
	if(k == 0)return 0;
	if(dp[k][n] != -1)return dp[k][n];
	return dp[k][n] = calc(k - 1, n - 1) + calc(k - 1, n);
}

int main()
{
	
	cin >> k >> n;
	
	for(int i = 0; i <= n; i++)dp[i][0] = 1;
	
	for(int i = 0; i <= k; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			dp[i][j] = -1;
		}
	}
	
	cout << calc(k, n) << endl;
	
	return 0;
}
