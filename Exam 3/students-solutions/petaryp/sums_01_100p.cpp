#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

ll n, a, b, s = 0;
ll arr[101];
bool dp[101][10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> a >> b;

	for (ll i = 1; i <= n; i++) {
		cin >> arr[i];
		s += arr[i];
	}

	for (ll i = 0; i <= n; i++) dp[i][0] = 1;

	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= s; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - arr[i] >= 0) {
				dp[i][j] |= dp[i - 1][j - arr[i]];
			}
		}
	}

	ll ans = 0;
	for (ll i = a; i <= b; i++) {
		for (ll j = 0; j <= n; j++) {
			if (dp[j][i]) {
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
}