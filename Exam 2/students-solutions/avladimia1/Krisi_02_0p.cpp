#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

int n, m, k, q;

void floyd(vector<vector<int>>& A) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (A[i][j] > A[i][k] + A[k][j]) {
					A[i][j] = A[i][k] + A[k][j];
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vector<vector<int>> graph(n, vector<int>(n, INT_MAX/2));

	int x, y, t;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> t;
		graph[x][y] = t;
		graph[y][x] = t;
		graph[x][x] = 0;
		graph[y][y] = 0;
	}

	cin >> k;
	vector<int> dest(k);
	for (auto& d : dest) cin >> d;

	cin >> q;
	vector<int> from(q);
	for (auto& d : from) cin >> d;

	floyd(graph);

	for (int f : from) {
		int mint = INT_MAX;
		for (int d : dest) {
			mint = min(mint, graph[d][f]);
		}
		cout << mint << endl; 
	}
}
