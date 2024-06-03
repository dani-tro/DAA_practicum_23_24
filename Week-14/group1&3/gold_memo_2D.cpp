#include <bits/stdc++.h>

using namespace std;

#define MAXN 52

#define MAXSUM 50010

int n, a[MAXN], dp[MAXN][MAXSUM];

int rec(int idx, int delta)
{
	if(idx > n)
    {
    	if(delta == 0)return 0;
    	return INT_MAX / 2;
	}
	
	if(dp[idx][delta] != -1)return dp[idx][delta];
	
	int ans = INT_MAX / 2;
	ans = min(ans, rec(idx + 1, delta + a[idx]));
	ans = min(ans, rec(idx + 1, delta - a[idx]));
	ans = min(ans, rec(idx + 1, delta) + a[idx]); 
	return dp[idx][delta] = ans;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        fill(dp[i], dp[i] + MAXSUM, -1);
    }
    
    cout << rec(1, 0) << endl;
    
    return 0;
}

