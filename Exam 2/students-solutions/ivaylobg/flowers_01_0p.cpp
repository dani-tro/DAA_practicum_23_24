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

const int MAX = 2e4 + 5;
std::vector<int> adj[MAX];
bool matrix[MAX][MAX];
bool used[MAX];
std::vector<int> garden[105];
int br = 0;

int k,l,m, max_flower = -1;

bool visited[MAX];
int deg[MAX];
int T[MAX];
std::priority_queue<int> S;
int tid;

void BFS(int max_flower)
{

	for (int i = 1; i <= max_flower; i++)
	{
		T[i] = -1;
		visited[i] = 0;
	}
	for (int i = 1; i <= max_flower; i++)
	{
		if (deg[i] == 0)
		{
			S.push(-i);
			visited[i] = 1;
		}
	}
	tid = 0;
	while (!S.empty())
	{
		int x = -S.top();
		S.pop();
		tid++; T[tid] = x;

		for (int y : adj[x])
		{
			deg[y]--;
			if (deg[y] == 0)
			{
				S.push(-y); visited[y] = 1;
			}
		}
	}
	if (tid < br) std::cout << "Fails.";
	else
	{
		/*for (size_t i = 1; i <= max_flower; i++)
		{
			if(used[i]) std::cout << T[i] << " ";
		}*/
		std::cout << "1";
	}
}

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    std::cin >> k;

	for (int i = 1; i < MAX; i++) used[i] = 0;
	//Build gardens
	for (size_t i = 0; i < k; i++)
	{
		std::cin >> l;
		for (size_t j = 0; j < l; j++)
		{
			std::cin >> m;
			if (max_flower < m) max_flower = m;       // find biggest flower number
			garden[i].push_back(m);

			if (!used[m]) br++;
			used[m] = 1;
		}
	}
	//Prepare matrix
	for (int i = 1; i < max_flower+5; i++)
	{
		deg[i] = 0;
		for (int j = 1; j < max_flower+5; j++)
		{
			matrix[i][j] = 0;
		}
	}
	//Build graph
	for (size_t idx = 0; idx < k; idx++)
	{
		for (size_t i = 0; i < garden[idx].size()-1; i++)
		{

			/*for (size_t j = i + 1; j < garden[idx].size(); j++)
			{
				int u = garden[idx][i];
				int v = garden[idx][j];

				if (matrix[u][v]) continue;
				adj[u].push_back(v);
				matrix[u][v] = 1;
				deg[v]++;
			}*/
			int u = garden[idx][i];
			int v = garden[idx][i+1];

			adj[u].push_back(v);
		}
	}
	//Print graph
	/*for (int i = 1; i <= 10; i++)
	{
		std::cout << i << " | ";
		for (int y : adj[i])
		{
			std::cout << y << " ";
		}
		std::cout << std::endl;
	}*/
	BFS(max_flower);
	//std::cout <<"\n" << br;
}