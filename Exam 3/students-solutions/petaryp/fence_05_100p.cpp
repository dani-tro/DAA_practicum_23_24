#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll s;
ll dp[2001][2001][2];
ll pref[2001][2001][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> s;

	for (ll i = 1; i <= s; i++) dp[i][i][0] = dp[i][i][1] = 1;

	for (ll i = 1; i <= s; i++) {
		for (ll j = 1; j <= i - 1; j++) {
			dp[i][j][0] += pref[i - j][j][1];
			dp[i][j][1] += pref[i - j][j][0];
		}
		for (ll j = 1; j <= s; j++) {
			pref[i][j][0] = (pref[i][j - 1][0] + dp[i][j - 1][0]) % MOD;
		}
		for (ll j = s - 1; j >= 0; j--) {
			pref[i][j][1] = (pref[i][j + 1][1] + dp[i][j + 1][1]) % MOD;
		}
	}
	//for (ll i = 1; i <= s; i++) {
	//	for (ll j = 1; j <= i; j++) {
	//		cout << dp[i][j][1] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;
	//for (ll i = 1; i <= s; i++) {
	//	for (ll j = 1; j <= i + 1; j++) {
	//		cout << pref[i][j][0] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	ll ans = 1;
	for (ll i = 1; i <= s - 1; i++) {
		ans = (ans + (dp[s][i][0] + dp[s][i][1]) % MOD) % MOD;
	}
	cout << ans << endl;
}

/*
6
1
0 1
1 0 1
2 0 0 1
2 1 0 0 1
4 2 0 0 0 1

1
0 1
0 1 1
0 0 1 1
0 1 1 1 1
0 2 1 1 1 1

12

8
*/