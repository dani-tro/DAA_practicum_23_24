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

vector<pair<ll, ll>> a;
vector<pair<ll, pair<ll, ll>>> edges;
ll par[1000];
ll d[1000];
ll n, ans = 0;

ll dist(pair<ll, ll> p1, pair<ll, ll> p2) {
	return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

ll find(ll p) {
	if (par[p] == p) return p;
	return par[p] = find(par[p]);
}

void uni(ll p1, ll p2) {
	auto pp1 = find(p1);
	auto pp2 = find(p2);
	if (d[pp2] > d[pp1]) swap(pp1, pp2);
	if (d[pp1] == d[pp2]) d[pp2]++;
	par[pp1] = pp2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		a.push_back({x, y});
		par[i] = i;
		d[i] = 1;
	}

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			edges.push_back({ dist(a[i], a[j]), make_pair(i, j) });
		}
	}
	sort(edges.begin(), edges.end());

	for (auto& x : edges) {
		if (find(x.second.first) != find(x.second.second)) {
			uni(x.second.second, x.second.first);
			ans += x.first;
		}
	}
	cout << ans << endl;
}