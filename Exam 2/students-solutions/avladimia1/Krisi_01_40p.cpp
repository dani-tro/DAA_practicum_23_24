#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

int n, m, k, q;

vector<int> djikstra(vector<vector<pii>>& graph, int source) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<bool> visited(n, 0);
	vector<int> dist(n, INT_MAX);

	dist[source] = 0;
	pq.push({ 0, source });

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (visited[u]) continue;
		visited[u] = true;

		for (auto &other : graph[u]) {
			int v = other.second;
			int w = other.first;

			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}

	return dist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vector<vector<pii>> graph(n);

	int x, y, t;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> t;
		graph[x].push_back({ t, y });
		graph[y].push_back({ t, x });
	}

	cin >> k;
	vector<int> dest(k);
	for (auto& d : dest) cin >> d;

	cin >> q;
	vector<int> from(q);
	for (auto& d : from) cin >> d;

	vector<int> mindist(q, INT_MAX);

	for (int d : dest) {
		vector<int> dist = djikstra(graph, d);
		int idx = 0;
		for (int i : from) {
			mindist[idx] = min(mindist[idx], dist[i]);
			idx++;
		}
	}

	for (auto i : mindist) {
		cout << i << endl;
	}
}
