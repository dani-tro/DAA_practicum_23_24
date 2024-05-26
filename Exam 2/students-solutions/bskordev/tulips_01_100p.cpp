#include <iostream>
#include <vector>
#include <map>

struct Position {
	int row;
	int column;
};

Position delta[4] = { { -1, 0 }, { 0 , -1 }, { 1, 0 }, { 0 , 1 } };

void dfs(std::vector<std::vector<int>>& g, int row, int column, std::vector<std::vector<bool>>& visited) {
	int n = g.size(), m = g[0].size();

	visited[row][column] = true;

	for (Position d : delta) {
		Position y = { row + d.row, column + d.column };
		if (0 <= y.row && y.row < n && 0 <= y.column && y.column < m
			&& !visited[y.row][y.column] && g[row][column] == g[y.row][y.column]) {
			dfs(g, y.row, y.column, visited);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> g(n, std::vector<int>(m));
	std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			std::cin >> x;

			g[i][j] = x;
		}
	}

	int result = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				result++;
				dfs(g, i, j, visited);
			}
		}
	}

	std::cout << result;

	return 0;
}