#include <iostream>
#include <vector>
#include <algorithm>

struct Position {
	long long x, y;

	bool operator<(Position const& other) const {
		return x < other.x || x == other.x && y < other.y;
	}
};

struct Edge {
	long long from, to;
	long long w;

	bool operator<(Edge const& other) const {
		return w < other.w;
	}
};

long long dist(Position const& a, Position const& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

long long find(std::vector<long long>& parent, long long u) {
	if (parent[u] == -1) {
		return u;
	}

	parent[u] = find(parent, parent[u]);
	return parent[u];
}

void unite(std::vector<long long>& parent, std::vector<long long>& d, long long u, long long v) {
	long long a = find(parent, u);
	long long b = find(parent, v);

	if (d[a] > d[b]) {
		parent[b] = a;
	}
	else {
		parent[a] = b;

		if (d[a] == d[b]) {
			d[b]++;
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	long long n;
	std::cin >> n;

	std::vector<Position> beetle;

	for (long long i = 0; i < n; i++) {
		long long x, y;
		std::cin >> x >> y;
		beetle.push_back({ x, y });
	}

	std::sort(beetle.begin(), beetle.end());

	std::vector<Edge> edges;

	for (long long i = 0; i < n; i++) {
		Position b = beetle[i];
		long long j = i + 1;
		while (j < n) {
			edges.push_back({ i, j, dist(b, beetle[j]) });
			j++;
		}
	}
	std::sort(edges.begin(), edges.end());

	std::vector<long long> parent(n, -1);

	std::vector<long long> d(n, 0);

	long long result = 0;

	for (Edge& e : edges) {
		if (find(parent, e.from) != find(parent, e.to)) {
			unite(parent, d, e.from, e.to);
			result += e.w;
		}
	}
	
	std::cout << result << std::endl;

	return 0;
}