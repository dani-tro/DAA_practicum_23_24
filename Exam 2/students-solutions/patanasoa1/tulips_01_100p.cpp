#include <iostream>
#include <utility>
#include <queue>
using namespace std;

const int MAX = 1007;
int n, m, ctr;
bool visited[MAX][MAX];
int matrix[MAX][MAX];
pair<int, int> moves[] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

bool inRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int i, int j) {
	queue<pair<int, int> > q;
	q.push({ i, j });
	visited[i][j] = true;
	
	while (!q.empty()) {
		auto& p = q.front();
		q.pop();
		for (auto& m : moves) {
			int x = p.first + m.first;
			int y = p.second + m.second;
			if (inRange(x, y) && !visited[x][y] && matrix[x][y] == matrix[i][j]) {
				visited[x][y] = true;
				q.push({ x, y });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				ctr++;
				bfs(i, j);
			}
		}
	}

	cout << ctr << endl;
}