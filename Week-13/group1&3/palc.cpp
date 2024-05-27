#include <bits/stdc++.h>

using namespace std;

#define MAX 128

#define MOD 1000000007

long long n, dp[MAX][MAX];

string s;

int main()
{
	cin >> s;
	n = s.size();
	
	for(int i = 0; i < n; i++)dp[i][i] = 1;
	for(int i = 0; i < n - 1; i++)
	{
		dp[i][i + 1] = 2 + (s[i] == s[i + 1]);
	}
	
	for(int len = 2; len < n; len++)
	{
		for(int i = 0; i < n - len; i++)
		{
			int j = i + len;
			if(s[i] == s[j])
			{
				dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
				dp[i][j] %= MOD;
			}
			else
			{
				dp[i][j] = ((dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]) % MOD + MOD) % MOD;
				dp[i][j] %= MOD;
			}
		}
	}
	
	cout << dp[0][n - 1] << endl;
	
	return 0;
}
