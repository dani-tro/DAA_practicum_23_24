#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;

void solve() {
	int n, m;
	ll k;
	cin >> n >> m >> k;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	vector<int> vals(n + 1);

	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		vals[l]++;
		vals[r]--;
	}

	vector<pii> order;
	for (int i = 0; i < n; ++i) {
		vals[i + 1] += vals[i];
		order.push_back({vals[i], i});
	}

	sort(order.rbegin(), order.rend());

	for (auto p : order) {
		if (k > arr[p.ss]) {
			k -= arr[p.ss];
			arr[p.ss] = 0;
		} else {
			arr[p.ss] -= k;
			k = 0;
			break;
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (ll) arr[i] * vals[i];
	}
	cout << ans << "\n";
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
}
