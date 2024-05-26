#include <iostream>
#include <vector>
#include <queue>
#include <list>

struct Vertex {
	int data;
	int t;

	bool operator<(Vertex const& other) const {
		return t > other.t;
	}
};

struct Edge {
	int to;
	int t;
};

struct Graph {
	std::vector<std::vector<Edge>> adj;

	Graph(int n) {
		adj = std::vector<std::vector<Edge>>(n);
	}

	void addEdge(int u, int v, int t) {
		adj[u].push_back({ v, t });
		adj[v].push_back({ u, t });
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	Graph g(n);
	for (int i = 0; i < m; i++) {
		int x, y, t;
		std::cin >> x >> y >> t;
		g.addEdge(x, y, t);
	}

	int k;
	std::cin >> k;

	std::vector<bool> visited(n, false);
	std::vector<int> d(n, -1);

	std::priority_queue<Vertex> pq;
	for (int i = 0; i < k; i++) {
		int x;
		std::cin >> x;

		d[x] = 0;
		pq.push({ x, d[x] });
	}

	while (!pq.empty()) {
		int x = pq.top().data;
		pq.pop();

		if (!visited[x]) {
			for (Edge const& e : g.adj[x]) {
				int y = e.to;
				int t = e.t;

				if (d[y] == -1 || d[y] > d[x] + t) {
					d[y] = d[x] + t;
					pq.push({ y, d[y] });
				}
			}

			visited[x] = true;
		}
	}

	int q;
	std::cin >> q;

	std::list<int> result;
	for (int i = 0; i < q; i++) {
		int u;
		std::cin >> u;

		result.push_back(d[u]);
	}

	for (int const& r : result) {
		std::cout << r << std::endl;
	}

	return 0;
}