#include <bits/stdc++.h>

using namespace std;

#define MAX 512

int n, a[MAX], pr[MAX], dp[MAX][MAX];

int get(int l, int r)
{
	return pr[r] - pr[l - 1];
}

int solve(int l, int r)
{
	if(l > r)return 0;
	if(l == r)return 0;
	if(dp[l][r])return dp[l][r];
	int ans = INT_MAX / 2;
	for(int i = l; i < r; i++)
	{
		ans = min(ans, solve(l, i) + solve(i + 1, r));
	}
	return dp[l][r] = ans + get(l, r);
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pr[i] = pr[i - 1] + a[i];
	}
	
	cout << solve(1, n) << endl;
	return 0;
}
