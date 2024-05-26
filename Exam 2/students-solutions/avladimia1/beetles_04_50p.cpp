#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <climits>
#include <algorithm>
#include <set>

using namespace std;

struct edge {
	int u, v;
	long long w;
	bool operator<(const edge& other) {
		return w < other.w;
	}
};

vector<int> parent;
vector<int> d;

int find(int u) {
	if (parent[u] == -1) return u;
	return parent[u] = find(parent[u]);
}

void uni(int u, int v) {
	u = find(u);
	v = find(v);
	if (d[u] > d[v]) {
		parent[v] = u;
	}
	else {
		parent[u] = v;
		if (d[u] == d[v]) d[u]++;
	}
}

void kruskal(vector<edge>& edges) {
	sort(edges.begin(), edges.end());

	long long mstw = 0;
	for (auto edge : edges) {
		if (find(edge.u) != find(edge.v)) {
			mstw += edge.w;
			uni(edge.u, edge.v);
		}
	}

	cout << mstw << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	parent.resize(n, -1);
	d.resize(n, 0);

	vector<pair<long, long>> inp(n);
	vector<edge> edges;
	edges.reserve((n * (n - 1)) / 2);

	for (int i = 0; i < n; i++) {
		cin >> inp[i].first >> inp[i].second;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			long long calc = (long long)(inp[i].first - inp[j].first) * (inp[i].first - inp[j].first) + (inp[i].second - inp[j].second) * (inp[i].second - inp[j].second);
			edges.push_back({ i, j, calc });
			edges.push_back({ j, i, calc });
		}
	}

	kruskal(edges);
}