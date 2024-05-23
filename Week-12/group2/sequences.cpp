#include<bits/stdc++.h>
#define ll long long
#define de(x) cout << #x << " = " << x << endl;
using namespace std;

const ll MOD = 998244353;
const int MAXN = 3e2 + 2;

ll n, m, k, dp[MAXN][MAXN], binom[MAXN][MAXN];

void init(){
	binom[0][0] = 1;
	for(int topki = 1; topki <= n; topki ++){
		for(int vzimam = 0; vzimam <= topki; vzimam ++){
			binom[topki][vzimam] = (binom[topki - 1][vzimam] + (vzimam > 0 ? binom[topki - 1][vzimam - 1] : 0)) % MOD;
		}
	}
}

int main(){
	cin >> n >> m >> k;
	init();
	dp[0][0] = 1;
	for(int used = 0; used <= n; used ++){
		for(int x = 0; x <= m; x ++){
			for(int _k = 0; _k <= k && used + _k <= n; _k ++){
				dp[used + _k][x + 1] = (dp[used + _k][x + 1] + (dp[used][x] * binom[n - used][_k]) % MOD) % MOD;
			}
		}
	}
	cout << dp[n][m] << endl;
}
