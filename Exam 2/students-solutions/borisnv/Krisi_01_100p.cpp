#include <ios>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define endl '\n'
int		  n, m, k, q;
const int MAXN = 100005;

struct Edge {
	int	 v, w;
	bool operator<(const Edge &other) const { return w > other.w; }
};

vector<Edge> g[MAXN];
bool		 vis[MAXN];
int			 d[MAXN];

void dijkstra(int s) {
	priority_queue<Edge> pq;
	pq.push({s, 0});

	while (!pq.empty()) {
		auto [u, l] = pq.top();
		pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		d[u]   = l;

		for (auto [v, w] : g[u]) {
			if (!vis[v]) pq.push({v, w + l});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int v;
		cin >> v;
		g[n].push_back({v, 0});
	}

	dijkstra(n);

	cin >> q;
	for (int i = 0; i < q; ++i) {
		int v;
		cin >> v;
		cout << d[v] << endl;
	}
	return 0;
}
