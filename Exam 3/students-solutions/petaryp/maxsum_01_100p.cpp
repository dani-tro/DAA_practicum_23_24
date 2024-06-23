#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <tuple>
using namespace std;
typedef long long ll;

ll n, k;
ll arr[100001];
ll moves[1001];
ll dp1[100001], dp2[100001];
pair<ll, ll> pref[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;

	for (ll i = 1; i <= n; i++) cin >> arr[i];
	for (ll i = 1; i <= k; i++) cin >> moves[i];
	for (ll i = 1; i <= n; i++) {
		dp1[i] = -1e16;
		dp2[i] = -1e16;
	}

	dp1[1] = arr[1];
	for (ll i = 2; i <= n - 1; i++) {
		for (ll j = 1; j <= k; j++) {
			if (i - moves[j] >= 1) {
				dp1[i] = max(dp1[i], arr[i] + dp1[i - moves[j]]);
			}
		}
	}
	dp2[n] = arr[n];
	pref[n].first = arr[n];
	pref[n].second = n;
	for (ll i = n - 1; i >= 2; i--) {
		for (ll j = 1; j <= k; j++) {
			if (i + moves[j] <= n) {
				dp2[i] = max(dp2[i], arr[i] + dp2[i + moves[j]]);
			}
		}
		pref[i].first = dp2[i];
		pref[i].second = i;
	}
	//for (ll i = 1; i <= n - 1; i++) {
	//	cout << dp1[i] << " ";
	//}
	//cout << endl;
	//for (ll i = 2; i <= n; i++) {
	//	cout << dp2[i] << " ";
	//}
	//cout << endl;
	sort(pref + 2, pref + n + 1, [](const auto& one, const auto& other) {
		return one.first > other.first;
	});
	//for (ll i = 1; i <= n - 1; i++) {
	//	cout << pref[i].second << " ";
	//}
	ll ans = -1e16;
	ll j = 2;
	for (ll i = 1; i <= n - 1; i++) {
		if (dp1[i] != -1e16) {
			while (j < n && pref[j].second <= i) {
				j++;
			}
			ans = max(ans, dp1[i] + pref[j].first);
		}
	}
	cout << ans << endl;
}