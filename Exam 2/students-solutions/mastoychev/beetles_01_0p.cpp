#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//const int MAX_SIZE = 100010;

/*truct edge {
	int u;
	int v;
	int w;
	bool operator<(const edge& other) {
		return w < other.w;
	}
};

vector<edge> edges;

vector<int> impV;

vector<int> hotels;

bool visited[MAX_SIZE];

int d[MAX_SIZE];

priority_queue<edge> dq;

vector<int> g[MAX_SIZE];

int djkstra(int v1, int v2) {
	fill(d, d + MAX_SIZE, INT_MAX / 2);
	d[v1] = 0;
	for (auto v : g[v1]) {

	}
}*/

long calc(long x1, long y1, long x2, long y2) {
	return (x1 - x2) ^ 2 + (y1 - y2) ^ 2;
}

struct edge {
	int u;
	int v;
	long w;
	bool operator<(const edge& other) {
		return w < other.w;
	}
};


const int MAX_SIZE = 100001;
priority_queue<edge> edges;
vector<int> g[MAX_SIZE];

pair<long, long> pairs[MAX_SIZE + 1];

int pr[MAX_SIZE];

long d[MAX_SIZE];
//
//int find(int a) {
//	if (pr[a] == -1) {
//		return a;
//	}
//	return find(pr[a]);
//}
//
//void uni(int a, int b) {
//	if (d[a] > d[b]) {
//		pr[b] = a;
//	}
//	else {
//		pr[a] = b;
//		if (d[a] == d[b]) {
//			d[b]++;
//		}
//	}
//}

bool visited[MAX_SIZE];

bool dali = false;

void dfs(int i) {
	if (visited[i]) {
		dali = true;
	}
	else {
		visited[i] = true;
		for (int v : g[i]) {
			dfs(v);
		}
	}
}

bool has_cycle(int u) {
	dfs(u);
	return dali;
}


int main()
{
	int n;
	cin >> n;
	long x, y;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		pairs[i].first = x;
		pairs[i].second = y;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			edges.push({ i, j, calc(pairs[i].first, pairs[i].second, pairs[j].first, pairs[j].second) });
		}
	}

	fill(pr, pr + MAX_SIZE, -1);

	long sum = 0;
	int cnt = 0;
	edge ed;
	while (cnt != n - 1) {
		dali = false;
		ed = edges.top();
		g[ed.u].push_back(ed.v);
		fill(visited, visited + MAX_SIZE, false);
		edges.pop();
		if (has_cycle(ed.u)) {
			g[ed.u].pop_back();
		}
		else {
			sum += ed.w;
			cnt++;
		}
	}
	cout << sum;
}

	/*
	int n;
	int m;
	cin >> n >> m;
	int u, v, w;
	for (int i = 0; i < m; i++) 
	{
		cin >> u >> v >> w;
		g[u].push_back(v);
		g[v].push_back(u);
		edges.push_back({ u, v, w });
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> v;
		impV.push_back(v);
	}
	int q;
	for (int i = 0; i < q; i++) {
		cin >> v;
		hotels.push_back(v);
	}*/


