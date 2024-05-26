#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1005
#define MAXE 1020000
int n, m, cnt;
int colors[MAX][MAX];
int par[MAXE], d[MAXE];


int find(int x) {
	if (par[x] == 0) return x;
	else return par[x] = find(par[x]);
}

int id(int x, int y) {
	return (x-1)*m + y;
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	cnt--;
	if (d[x] < d[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (d[x] == d[y]) d[x]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	cnt = n * m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> colors[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			
			if (i > 1 && colors[i - 1][j] == colors[i][j]) {
				uni(id(i - 1, j), id(i, j));
			}
			if (j > 1 && colors[i][j - 1] == colors[i][j]) {
				uni(id(i , j-1), id(i, j));
			}
		}
	}
	cout << cnt << endl;
	return 0;
}