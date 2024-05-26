#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 1005;
int		  n, m;
int		  M[MAXN][MAXN];
bool	  vis[MAXN][MAXN];
struct Dir {
	int u, v;
};
const vector<Dir> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(Dir s) {
	queue<Dir> q;
	q.push(s);
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		if (vis[x][y]) continue;
		vis[x][y] = 1;

		for (auto [x1, y1] : dirs) {
			Dir w{x + x1, y + y1};
			auto &[u, v] = w;
			if (u >= 0 && u < n && v >= 0 && v < m && !vis[u][v] && M[x][y] == M[u][v]) q.push(w);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> M[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!vis[i][j]) {
				++cnt;
				dfs({i, j});
			}
		}
	}
	cout << cnt << endl;
}
