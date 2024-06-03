#include <bits/stdc++.h>

using namespace std;

#define MAX 512

int n, a[MAX], dp[MAX][MAX], pr[MAX];

int get(int l, int r)
{
	return pr[r] - pr[l - 1];
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pr[i] = pr[i - 1] + a[i];
	}
	
	
	for(int len = 1; len <= n; len++)
	{
		for(int i = 1; i <= n - len; i++)
		{
			int j = i + len;
			dp[i][j] = INT_MAX / 2;
			
			for(int k = i; k < j; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + get(i, j));
			}
		}
	}
	
	cout << dp[1][n] << endl;
	
	return 0;
}
