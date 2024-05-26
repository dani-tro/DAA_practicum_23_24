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
}*/;

const int MAX_SIZE = 20001;

vector<int> flowers[MAX_SIZE];

bool visited[MAX_SIZE];

queue<int> q;

bool checked[MAX_SIZE];

bool dali = true;

void dfs(int i) {
	if (checked[i]) {
		return;
	}
	if (visited[i]) {
		dali = false;
	}
	else {
		visited[i] = true;
		for (int v : flowers[i]) {
			dfs(v);
		}
		checked[i] = true;
	}
}



bool dfs_check() {
	int u;
	for (int i = 1; i < MAX_SIZE; i++) {
		if (checked[i]) {
			continue;
		}
		fill(visited, visited + MAX_SIZE, false);
		dfs(i);
	}
	return dali;
}

int main()
{
	int k;
	cin >> k;
	int n;
	int f;
	int prev = 0;
	for (int i = 0; i < k; i++) {
		cin >> n;
		prev = 0;
		for (int j = 0; j < n; j++) {
			cin >> f;
			flowers[prev].push_back(f);
			prev = f;
		}
	}
	cout << dfs_check();
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


