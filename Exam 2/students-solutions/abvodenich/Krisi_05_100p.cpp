#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#define MAX 101000
using namespace std;

int n, m, q, x, y, k, t, d[MAX];
vector<pair<int, int>> g[MAX];
queue<int> ans;
priority_queue<pair<int, int>> pq;
bool visited[MAX];

void dijkstra(int s) {
	d[s] = 0;
	pq.push({ 0, s });
	visited[s] = true;

	while (!pq.empty()) {
		int node = pq.top().second;
		visited[node] = true;
		pq.pop();

		for (pair<int, int> p : g[node]) {

			if (!visited[p.first] && d[p.first] > d[node] + p.second) {
				d[p.first] = d[node] + p.second;
				pq.push({ -d[p.first], p.first});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> t;
		g[x].push_back({ y, t });
		g[y].push_back({ x, t });
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> x;
		g[n].push_back({ x, 0 });
	}

	fill(d, d + n + 2, INT_MAX / 2);
	dijkstra(n);

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> x;
		ans.push(d[x]);
	}

	while (!ans.empty()) {
		cout << ans.front() << endl;
		ans.pop();
	}

	return 0;
}