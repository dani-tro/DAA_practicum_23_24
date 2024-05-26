#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <tuple>
#include <stack>
#include <array>
#include <set>
using namespace std;
typedef long long ll;

vector<ll> layers[11];
pair<ll, ll> a[500000];
ll n, ans = 0;

ll dist(pair<ll, ll> p1, pair<ll, ll> p2) {
	return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		layers[y].push_back(x);
		a[i] = { x, y };
	}
	sort(a, a + n + 1);

	ans = 0;
	for (ll i = 0; i < n; i++) {
		sort(a + i + 1, a + i + 1 + min((ll)10, n - i - 1), [=](const auto& x, const auto& y) {
			return dist(x, a[i]) < dist(y, a[i]);
			});
		ans += dist(a[i], a[i + 1]);
	}
	cout << ans << endl;
}