#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

#define MAXN 1024

#define MAXS 6020

long long dp[MAXN][MAXS];

bool calculated[MAXN][MAXS];

long long calc(int n, int s)
{
	if(s < 0)return 0;
	if(s == 0)return (n == 0);
	if(n == 0)return 0; // (s == 0)
	
	//if(dp[n][s] != -1)return dp[n][s];
	if(calculated[n][s])return dp[n][s];
	calculated[n][s] = true;

	long long ans = 0;
	for(int i = 1; i <= 6; i++)ans += calc(n - 1, s - i);
	
	return dp[n][s] = ans % MOD;
}

int main()
{
	int n, s;
	cin >> n >> s;
	
	for(int i = 0; i < MAXN; i++)
	{
		fill(dp[i], dp[i] + MAXS, -1);
	}
	
	cout << calc(n, s) << endl;
	
	return 0;
}
