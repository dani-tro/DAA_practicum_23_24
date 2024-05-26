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

vector<ll> g[20001];
queue<ll> q;
bool temp[20001];
ll in[20001];
ll k, c = 0, un = 0;

bool topoSort() {
	for (ll i = 1; i <= 20000; i++) {
		if (temp[i] == 1) un++;
		if (temp[i] == 1 && in[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		ll curr = q.front();
		q.pop();
		c++;
		for (auto x : g[curr]) {
			in[x]--;
			if (in[x] == 0) {
				q.push(x);
			}
		}
	}
	//cout << c << endl;
	return c == un;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> k;
	for (ll i = 1; i <= k; i++) {
		ll s;
		cin >> s;

		if (s == 0) continue;
		ll prev;
		cin >> prev;
		temp[prev] = true;

		for (ll j = 1; j < s; j++) {
			ll curr;
			cin >> curr;
			temp[curr] = true;
			g[prev].push_back(curr);
			in[curr]++;
			prev = curr;
		}
	}
	//for (ll i = 1; i <= 20000; i++) {
	//	if (temp[i]) {
	//		cout << i << ": ";
	//		for (auto x : g[i]) {
	//			cout << x << " ";
	//		}
	//		cout << endl;
	//	}
	//}
	cout << topoSort() << endl;
}