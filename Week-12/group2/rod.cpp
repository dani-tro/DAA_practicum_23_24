#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 3;
const int INF = 2e9;

int A[MAXN], dp[MAXN][MAXN], pref[MAXN];

int main(){
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++){
		dp[i][j] = INF;
	}
	for(int i = 1; i <= n; i ++){
		dp[i][i] = 0;
	}
	for(int i = 1; i <= n; i ++){
		cin >> A[i];
	}
	for(int i = 1; i <= n; i ++){
		pref[i] = pref[i - 1] + A[i];
	}
	for(int len = 2; len <= n; len ++){
		for(int l = 1, r = len; r <= n; l ++, r ++){
			for(int m = l; m <= r - 1; m ++){
				dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r] + pref[r] - pref[l - 1]);
			}
		}
	}
	cout << dp[1][n] << endl;
}
