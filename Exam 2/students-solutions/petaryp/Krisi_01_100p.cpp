#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <tuple>
#include <stack>
#include <array>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>> g[100001];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
ll d[100001];
ll n, m, k, q;

void dijkstra() {
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		ll curr = p.second;

		for (auto x : g[curr]) {
			if (d[x.first] > d[curr] + x.second) {
				d[x.first] = d[curr] + x.second;
				pq.push({ d[x.first], x.first });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (ll i = 1; i <= m; i++) {
		ll x, y, t;
		cin >> x >> y >> t;
		g[x].push_back({ y, t });
		g[y].push_back({ x, t });
	}

	for (ll i = 0; i < n; i++) {
		d[i] = 1e16;
	}

	cin >> k;
	for (ll i = 1; i <= k; i++) {
		ll x;
		cin >> x;
		pq.push({ 0, x });
		d[x] = 0;
	}

	dijkstra();

	cin >> q;
	for (ll i = 1; i <= q; i++) {
		ll to;
		cin >> to;

		cout << d[to] << endl;
	}
}