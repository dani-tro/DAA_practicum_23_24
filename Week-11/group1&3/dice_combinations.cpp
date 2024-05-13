#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

#define MAX 1000100

long long dp[MAX];

long long calc(int n)
{

	if(n < 0)return 0;
	if(n == 0)return 1;
	
	if(dp[n])return dp[n];
	
	long long ans = 0;
	for(int i = 1; i <= 6; i++)ans += calc(n - i);
	
	return dp[n] = ans % MOD;
}

int main()
{
	int n;
	cin >> n;
	
	cout << calc(n) << endl;
	
	return 0;
}
