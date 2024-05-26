#include <iostream>
#include <vector>

using namespace std;

short matrix[1000][1000];
bool visited[1000][1000];

short n, m;

void dfs(short row, short colm) {		
	if (visited[row][colm])
	{
		return;
	}
	visited[row][colm] = true;
	if (row < n - 1 && matrix[row][colm] == matrix[row + 1][colm]) {
		dfs(row + 1, colm);
	}
	if (colm < m - 1 && matrix[row][colm] == matrix[row][colm+1]) {
		dfs(row, colm + 1);
	}
}

long find_max() {
	long sum = 0;
	for (short i = 0; i < n; i++)
	{
		for (short j = 0; j < m; j++)
		{
			if (!visited[i][j]) {
				dfs(i, j);
				sum++;
			}
		}
	}
	return sum;
}


int main()
{
   cin >> n >> m;
	for (short i = 0; i < n; i++)
	{
		for (short j = 0; j < m; j++)
		{
			cin >> matrix[i][j];
		}
	}
	cout << find_max() << endl;
}