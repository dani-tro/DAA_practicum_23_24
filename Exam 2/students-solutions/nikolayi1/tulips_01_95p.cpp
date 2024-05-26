#include <iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

const int MAX = 1005;
int map[MAX][MAX];
vector<vector<vector<pair<int, int>>>> conns;

void addVertex(pair<int, int> a, pair<int, int> b) {
	conns[a.first][a.second].push_back(b);
	conns[b.first][b.second].push_back(a);
}

void bfs(pair<int, int> start) {
	queue<pair<int, int>> q;
	q.push(start);
	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();
		vector<pair<int, int>> currN = conns[curr.first][curr.second];
		for (int i = 0; i < currN.size(); ++i) {
			if (map[currN[i].first][currN[i].second] != -1) {
				q.push(currN[i]);
				map[currN[i].first][currN[i].second] = -1;
			}
		}

		map[curr.first][curr.second] = -1;
	}
	
	return;
}

int main() {
	int i, j, n, m;

	cin >> n >> m;

	

	for (i = 0; i < n; ++i) {
		vector<vector<pair<int, int>>> v;
		conns.push_back(v);
		for (j = 0; j < m; ++j) {
			vector<pair<int, int>> vec;
			conns[i].push_back(vec);
		}
	}
	for (i = 0; i < m; ++i) {
		cin >> map[0][i];
		if (i > 0 && map[0][i - 1] == map[0][i]) {
			addVertex(make_pair(0, i - 1), make_pair(0, i));
		}
	}
	for (i = 1; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i - 1][j] == map[i][j]) {
				addVertex(make_pair(i - 1, j), make_pair(i, j));
			}

			if (j > 0 && map[i][j - 1] == map[i][j]) {
				addVertex(make_pair(i, j - 1), make_pair(i, j));
			}
		}
	}

	int count = 0;
	
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (map[i][j] != -1) {
				bfs(make_pair(i, j));
				count++;
			}
		}
	}

	cout << count;
}