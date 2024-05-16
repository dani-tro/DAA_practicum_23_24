#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
const int MAXN = 6e3 + 3;

int dp[2][MAXN];

int main(){
	int n, s; cin >> n >> s;
	dp[0][0] = 1; // base case
	for(int b = 1; b <= n; b ++){
		for(int i = 0; i <= s; i ++){
			dp[b % 2][i] = 0;
		}
		for(int sum = 0; sum <= s; sum ++){
			for(int x = 1; x <= 6; x ++){
				if(sum - x >= 0){
					dp[b % 2][sum] = (dp[b % 2][sum] + dp[(b - 1) % 2][sum - x]) % MOD;
				}
			}
		}
	}
	cout << dp[n % 2][s] << endl;
}
