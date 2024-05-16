#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e6 + 3;

ll n, x, dp[MAXN], w[MAXN], v[MAXN], max_value;

int main(){
	cin >> n >> x;
	for(int i = 1; i <= n; i ++){
		cin >> w[i] >> v[i];
		max_value += v[i];
	}
	dp[0] = 0;
	for(int i = 1; i <= max_value; i ++){
		dp[i] = x + 1;
	}
	for(int i = 1; i <= n; i ++){
		for(int j = max_value; j >= 0; j --){
			if(j - v[i] >= 0){
				dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
			}
		}
	}
	ll ans = 0;
	for(int i = max_value; i >= 0; i --){
		if(dp[i] <= x){
			ans = i;
			break;
		}
	}
	cout << ans << endl;
}
