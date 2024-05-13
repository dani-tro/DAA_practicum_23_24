#include <bits/stdc++.h>

using namespace std;

#define MAXN 128

#define inf 1000100

int n, x, c[MAXN], dp[inf];

int calc(int x)
{
	if(x == 0)return 0;
	if(x < 0)return inf;
	
	if(dp[x])return dp[x];
	
	int ans = INT_MAX;
	for(int i = 0; i < n; i++)
	{
		ans = min(ans, 1 + calc(x - c[i]));
	}
	return dp[x] = ans;
}

int main()
{
	cin >> n >> x;
	for(int i = 0; i < n; i++)cin >> c[i];
	
	
	int ans = calc(x);
	if(ans < inf)cout << ans << endl;
	else cout << "-1" << endl;
	
	return 0;
}
