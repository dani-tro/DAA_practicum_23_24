#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e6 + 3;

ll n, x, dp[MAXN], w[MAXN], v[MAXN];

int main(){
	cin >> n >> x;
	for(int i = 1; i <= n; i ++){
		cin >> w[i] >> v[i];
	}
	dp[0] = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = x; j >= 0; j --){
			if(j - w[i] >= 0){
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= x; i ++){
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
