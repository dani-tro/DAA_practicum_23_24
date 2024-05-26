//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> gr;
vector<vector<bool>> visited;
int br = 1;

void uni(int startI, int endI)
{
	for (int i = startI; i < n - 1; ++i)
	{
		for (int j = endI; j < m - 1; ++j)
		{
			if (visited[i][j]) continue;
			bool flag1 = gr[i][j] == gr[i + 1][j];
			bool flag2 = gr[i][j] == gr[i][j + 1];
			if (flag1)
			{
				if (i + 1 >= n - 1)
				{
					visited[i + 1][j] = true;
					br++;
					return;
				}
				visited[i][j] = true;
				uni(i + 1, j);
			}
			if (flag2)
			{
				if (j + 1 >= m - 1)
				{
					visited[i][j + 1] = true;
					br++;
					return;
				}
				visited[i][j] = true;
				uni(i, j + 1);
			}
			if (!flag1 && !flag2)
			{
				br++;
			}
		}
	}
	if (m > 1)
		if (gr[n - 1][m - 1] != gr[n - 1][m - 2]) br++;
	if (n > 1)
		if (gr[n - 1][m - 1] != gr[n - 2][m - 1]) br++;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		gr.push_back({});
		visited.push_back({});
		for (int j = 0; j < m; ++j)
		{
			int a;
			cin >> a;
			gr[i].push_back(a);
			visited[i].push_back(false);
		}
	}

	uni(0,0);
	std::cout << br;
}