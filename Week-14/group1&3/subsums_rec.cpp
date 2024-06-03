#include <bits/stdc++.h>

using namespace std;

#define MAXN 1024

#define MAXSUM 200100

#define offset 100100

int n, a[MAXN], ans;
bool dp[MAXSUM];
void calc(int k, int sum, bool fl=false)
{
	if(k > n) {
		if(fl)dp[sum + offset] = true;
		return ;
	}
	calc(k+1, sum, fl);
	calc(k+1, sum + a[k], true);
	 
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	calc(1, 0);
	
	for(int i = 0; i < MAXSUM; i++)ans += dp[i];
	
	cout << ans << endl;
	
	return 0;
}
