#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
const int MAXN = 1e2 + 2;

bool calc[MAXN][MAXN];
ll dp[MAXN][MAXN];
string t;

ll solve(int l, int r){
	if(calc[l][r]) return dp[l][r];
	calc[l][r] = true;
	for(int L = l; L <= r; L ++){
		for(int R = L + 1; R <= r; R ++){
			if(t[L] == t[R]){
				dp[l][r] = (dp[l][r] + solve(L + 1, R - 1) + 1) % MOD;
			}
		}
	}
	dp[l][r] = (dp[l][r] + (r - l + 1)) % MOD;
	return dp[l][r];
}

int main(){
	cin >> t;
	cout << solve(0, t.size() - 1) << endl;
}
