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

pair<ll, ll> a[100000];
ll n;

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
		a[i] = { x, y };
	}
	sort(a, a + n);

	ll ans = 0;
	for (ll i = 0; i < n - 1; i++) {
		ans += dist(a[i], a[i + 1]);
	}
	cout << ans << endl;
}