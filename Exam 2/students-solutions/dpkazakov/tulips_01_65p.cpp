#include<iostream>
#include<vector>
#include<queue>
#include<climits>

#define MAXN 2048

using namespace std;

vector<int> gr[MAXN]; //[v] -> u,w
bool visited[MAXN];
int arr[MAXN][MAXN];

int n, m, k, q;

int id(int x, int y)
{
	return x * m + y;
}

void dfs(int start)
{
	if (visited[start])
	{
		return;
	}

	visited[start] = true;
	for (auto v : gr[start])
	{
		dfs(v);
	}
}


int cc()
{
	int count = 0;
	for (size_t i = 0; i < n*m; i++)
	{
		if (!visited[i])
		{
			count++;
			dfs(i);
		}
	}
	return count;
}

int main()
{
	cin >> n >> m;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			if (i > 0 && arr[i][j] == arr[i - 1][j])
			{
				gr[id(i - 1, j)].push_back(id(i, j));
				gr[id(i , j)].push_back(id(i-1, j));

			}

			if (j > 0 && arr[i][j] == arr[i][j-1])
			{
				gr[id(i, j-1)].push_back(id(i, j));
				gr[id(i, j)].push_back(id(i, j-1));

			}
		}
	}

	cout << cc();
}