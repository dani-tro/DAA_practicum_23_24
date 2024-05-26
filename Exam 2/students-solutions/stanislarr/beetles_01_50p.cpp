#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100000

int n;
int parent[MAX];
int depth[MAX];
pair<int, int> graph[MAX];
unsigned long long ans;

unsigned long long calculate(long long xi, long long yi, long long xj, long long yj) {
	long long a = xi - xj;
	long long b = yi - yj;
	return a * a + b * b;
}

struct edge {
	int u, v;
	unsigned long long w;

	bool operator<(const edge& other) const {
		return this->w < other.w;
	}
};

vector <edge> edges;

int find(int a) {
	if (parent[a] == -1) return a;
	return parent[a] = find(parent[a]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);

	if (depth[a] > depth[b]) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
		if (depth[a] == depth[b]) depth[b]++;
	}
}

void kruskal() {
	sort(edges.begin(), edges.end());

	for (auto ed : edges) {
		if (find(ed.u) != find(ed.v)) {
			ans += ed.w;
			uni(ed.u, ed.v);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	long long x, y;

	for (int i = 0; i < n; i++) {
		parent[i] = -1;
		cin >> x >> y;
		graph[i] = { x, y };

		for (int j = 0; j < i; j++) {
			unsigned long long weight = calculate(x, y, graph[j].first, graph[j].second);
			edges.push_back({i ,j, weight});
			edges.push_back({j, i, weight});
		}
	}

	kruskal();

	cout << ans << endl;

	return 0;
}