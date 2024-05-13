#include <bits/stdc++.h>

using namespace std;

#define MAX 101000

int n, a[MAX], dp[MAX];

long long calc(int idx)
{
	if(idx > n)return 0;
	if(idx >= n - 1)return a[idx];
	if(dp[idx])return dp[idx];
	
	long long ans = 0;
	ans = max(a[idx] + calc(idx + 2), a[idx] + calc(idx + 3));
	
	return dp[idx] = ans;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	
	cout << max(calc(1), calc(2)) << endl;
	return 0;
}
