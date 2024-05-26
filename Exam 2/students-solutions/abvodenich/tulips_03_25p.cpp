#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1005
#define MAXE 1020000
int n, m;
int colors[MAX][MAX];
vector<int> adj[MAXE];
bool visited[MAXE];
queue<int> q;

void bfs(int u) {
	q.push(u);
	visited[u] = true;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (visited[v]) continue;
			visited[v] = true;
			q.push(v);
		}
	}
}

int ccomponents() {
	int counter = 0;
	for (int i = 0; i < n * m; i++) {
		if (!visited[i]) {
			counter++;
			bfs(i);
		}
	}
	return counter;
}

int id(int x, int y) {
	return x * y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> colors[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			if (i > 1 && colors[i - 1][j] == colors[i][j]) {
				adj[id(i-1, j)].push_back(id(i, j));
				adj[id(i, j)].push_back(id(i-1, j));
			}
			if (j > 1 && colors[i][j - 1] == colors[i][j]) {
				adj[id(i, j - 1)].push_back(id(i, j));
				adj[id(i, j)].push_back(id(i, j - 1));
			}
		}
	}

	cout << ccomponents() << endl;
	return 0;
}