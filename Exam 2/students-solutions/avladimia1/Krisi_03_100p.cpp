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
	vector<bool> visited(n+1, 0);
	vector<int> dist(n + 1, INT_MAX);

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

	vector<vector<pii>> graph(n+1);

	int x, y, t;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> t;
		graph[x].push_back({ t, y });
		graph[y].push_back({ t, x });
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> x;
		graph[n].push_back({ 0, x });
	}

	vector<int> dist = djikstra(graph, n);

	cin >> y;
	for (int i = 0; i < y; i++) {
		cin >> x;
		cout << dist[x] << endl;
	}
}