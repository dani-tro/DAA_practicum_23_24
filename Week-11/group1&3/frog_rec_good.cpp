#include <bits/stdc++.h>

using namespace std;

#define MAX 101000

int n, h[MAX], dp[MAX];

long long calc(int idx)
{
	if(idx > n)return INT_MAX;
	if(idx == n)return 0;
	if(dp[idx] != -1) return dp[idx];
	
	
	return dp[idx] = min(abs(h[idx] - h[idx + 1]) + calc(idx + 1), 
			abs(h[idx] - h[idx + 2]) + calc(idx + 2));
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> h[i];
	
	for(int i = 0; i < MAX; i++)
	{
		dp[i] = -1;
	}
	
	cout << calc(1) << endl;
	
	return 0;
}
