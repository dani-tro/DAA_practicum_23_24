#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
const int MAXN = 6e3 + 3;

bool calc[MAXN][MAXN];
int dp[MAXN][MAXN];

int rec(int n, int s){
	if(n < 0 || s < 0) return 0;
	if(n == 0 && s == 0) return 1;
	if(calc[n][s]) return dp[n][s];
	calc[n][s] = true;
	int ans = 0;
	for(int x = 1; x <= 6; x ++){
		ans = (ans + rec(n - 1, s - x)) % MOD;
	}
	return dp[n][s] = ans;
}

int main(){
	int n, s; cin >> n >> s;
	cout << rec(n, s) << endl;
}
