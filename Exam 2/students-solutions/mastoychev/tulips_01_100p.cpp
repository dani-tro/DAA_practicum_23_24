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

const int MAX_SIZE = 1001;

int mat[MAX_SIZE][MAX_SIZE];

int cnt = 0;

bool visited[MAX_SIZE][MAX_SIZE];

int n, m;

int curr;

void mark(int x, int y) {
	if (visited[x][y]) {
		return;
	}
	if (mat[x][y] == curr) {
		visited[x][y] = true;
		if (x == n - 1) {
			if (y == m - 1) {
				return;
			}
			else {
				mark(x, y + 1);
			}
		}
		else {
			if (y == m - 1) {
				mark(x + 1, y);
			}
			else {
				mark(x + 1, y);
				mark(x, y + 1);
			}
		}
		
	}
}

void count(int x = 0, int y = 0) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) {
				continue;
			}
			cnt++;
			curr = mat[i][j];
			visited[i][j] = true;
			if (i == n - 1) {
				if (j == m - 1) {
					return;
				}
				else {
					mark(i, j + 1);
				}
			}
			else {
				if (j == m - 1) {
					mark(i + 1, j);
				}
				else {
					mark(i + 1, j);
					mark(i, j + 1);
				}
			}
		}
	}
	
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < MAX_SIZE; i++) {
		fill(visited[i], visited[i] + MAX_SIZE, false);
	}

	count();

	cout << cnt;
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


