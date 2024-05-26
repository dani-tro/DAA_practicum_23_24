#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <climits>
#include <set>

using namespace std;

int n, m;
vector<vector<int>> visited(1010, vector<int>(1010, 0));

void dfs(vector<vector<int>>& gr, int x, int y, int prev) {
	if (x < 0 || y < 0 || x >= n || y >= m || prev != gr[x][y]) return;

	if (!visited[x][y]) {
		visited[x][y] = 1;
		dfs(gr, x, y + 1, gr[x][y]);
		dfs(gr, x + 1, y, gr[x][y]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	vector<vector<int>> gr(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> gr[i][j];
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				count++;
				dfs(gr, i, j, gr[i][j]);
			}
		}
	}

	cout << count;
}