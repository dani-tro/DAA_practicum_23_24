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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> s;

	//dp[0][1][0] = dp[0][1][1] = 1;
	dp[1][1][0] = 1;

	for (ll i = 2; i <= s; i++) {
		for (ll j = 1; j <= i; j++) {
			if (i == j) {
				dp[i][j][0]++;
				dp[i][j][1]++;
				dp[i][j][0] %= MOD;
				dp[i][j][1] %= MOD;
				continue;
			}
			for (ll p = 1; p <= j - 1; p++) {
				dp[i][j][1] += dp[i - j][p][0];
				dp[i][j][1] %= MOD;
			}
			for (ll p = j + 1; p <= i; p++) {
				dp[i][j][0] += dp[i - j][p][1];
				dp[i][j][0] %= MOD;
			}
		}
	}

	ll ans = 0;
	for (ll i = 1; i <= s; i++) {
		ans = (ans + (dp[s][i][0] + dp[s][i][1]) % MOD) % MOD;
	}
	cout << (ans - 1 + MOD) % MOD << endl;
}