#include <iostream>
#include <stdio.h>
#include <stack>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <queue>
#include <climits>

const int MAX = 1e3 + 5;
const int BigMAX = 1e6 + 5;
int n, m, br_node, counter;
struct node
{
	int x, y;
};
std::vector<int> adj[BigMAX];
int matrix[MAX][MAX];

bool visited[BigMAX];

int ID(node a)
{
	return a.x * m + a.y;
}
void DFS_Visit(int x)
{
	visited[x] = true;

	for (int y : adj[x])
	{
		if (!visited[y])
		{
			DFS_Visit(y);
		}
	}
}
void DFS()
{
	for (size_t i = 0; i < n; i++)
	{
		visited[i] = false;
	}
	counter = 0;
	for (size_t i = 0; i < br_node; i++)
	{
		if (!visited[i]) { DFS_Visit(i); counter++; }
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) 
		{
			std::cin >> matrix[i][j];
		}
	}
	br_node = n * m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			node curr = { i,j };
			node left = { i,j - 1 }; // j > 0
			node right = { i, j + 1 }; //j < m-1
			node up = { i - 1, j }; // i > 0
			node down = { i + 1, j }; // i < n-1

			if (j > 0 && matrix[i][j] == matrix[i][j-1]) adj[ID(curr)].push_back(ID(left));
			if (j < m-1 && matrix[i][j] == matrix[i][j + 1]) adj[ID(curr)].push_back(ID(right));
			if (i > 0 && matrix[i][j] == matrix[i-1][j]) adj[ID(curr)].push_back(ID(up));
			if (i < n-1 && matrix[i][j] == matrix[i+1][j]) adj[ID(curr)].push_back(ID(down));
		}
	}
	/*for (int i = 0; i < br_node; i++)
	{
		std::cout << i << " | ";
		for (int y : adj[i])
		{
			std::cout << y << " ";
		}
		std::cout <<"\n";
	}*/
	DFS();
	std::cout << counter <<"\n";
}