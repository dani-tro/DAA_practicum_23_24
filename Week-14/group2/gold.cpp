#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MAXN = 50;
const int MAXA = 1000;
const int INF = 1e9;

int dp[2][MAXN * MAXA + 5];

int main(){
	int n; cin >> n;
	for(int i = 1; i <= MAXN * MAXA; i ++){
		dp[0][i] = INF;
	}
	for(int i = 1; i <= n; i ++){
		int x; cin >> x;
		for(int j = 0; j <= MAXN * MAXA; j ++){
			dp[i % 2][j] = INF;
		}
		for(int prv_bal = 0; prv_bal <= MAXN * MAXA; prv_bal ++){
			if(dp[(i - 1) % 2][prv_bal] == INF) continue;
			if(prv_bal + x <= MAXN * MAXA){
				dp[i % 2][prv_bal + x] = min(dp[i % 2][prv_bal + x], dp[(i - 1) % 2][prv_bal]);
			}
			if(abs(prv_bal - x) <= MAXN * MAXA){
				dp[i % 2][abs(prv_bal - x)] = min(dp[i % 2][abs(prv_bal - x)], dp[(i - 1) % 2][prv_bal]);
			}
			dp[i % 2][prv_bal] = min(dp[i % 2][prv_bal], dp[(i - 1) % 2][prv_bal] + x);
		}
	}
	cout << dp[n % 2][0] << endl;
}
