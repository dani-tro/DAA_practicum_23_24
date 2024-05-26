#include <iostream>

using namespace std;

#define MAX 1000

int n, m;
int matrix[MAX][MAX];
bool used[MAX * MAX];
int ans;

int id(int x, int y) {
	return x * m + y;
}

bool isValid(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(int startX, int startY) {
	int index = id(startX, startY);

	used[index] = true;

	if (isValid(startX - 1, startY)) {
		if (!used[id(startX - 1, startY)] && matrix[startX - 1][startY] == matrix[startX][startY]) {
			used[id(startX - 1, startY)] = true;
			dfs(startX - 1, startY);
			
		}
	}

	if (isValid(startX + 1, startY)) {
		if (!used[id(startX + 1, startY)] && matrix[startX + 1][startY] == matrix[startX][startY]) {
			used[id(startX + 1, startY)] = true;
			dfs(startX + 1, startY);
			
		}
	}

	if (isValid(startX, startY - 1)) {
		if (!used[id(startX, startY - 1)] && matrix[startX][startY - 1] == matrix[startX][startY]) {
			used[id(startX, startY - 1)] = true;
			dfs(startX, startY - 1);
			
		}
	}

	if (isValid(startX, startY + 1)) {
		if (!used[id(startX, startY + 1)] && matrix[startX][startY + 1] == matrix[startX][startY]) {
			used[id(startX, startY + 1)] = true;
			dfs(startX, startY + 1);
			
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int index = id(i, j);
			if (!used[index]) {
				ans++;
				dfs(i, j);
			}
			
		}
	}

	cout << ans << endl;

	return 0;
}