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

ll a[1001][1001];
bool visited[1001][1001];
ll c = 0;
ll n, m;

void dfs(ll i, ll j, ll color) {
	if (i < 0 || j < 0 || i >= n || j >= m) return;
	if (visited[i][j]) return;
	if (a[i][j] != color) return;
	visited[i][j] = true;

	dfs(i + 1, j, color);
	dfs(i, j + 1, color);
	dfs(i, j - 1, color);
	dfs(i - 1, j, color);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			if (!visited[i][j]) {
				dfs(i, j, a[i][j]);
				c++;
			}
		}
	}
	cout << c << endl;
}