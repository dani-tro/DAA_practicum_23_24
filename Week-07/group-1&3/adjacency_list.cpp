#include <bits/stdc++.h>

using namespace std;

#define MAX 1010

int n, m, a, b, c, v;

vector< int > graph[MAX];

bool used[MAX];

void bfs(int node)
{
	queue<int> q;
	q.push(node);
	used[node] = true;
	while(!q.empty())
	{
		node = q.front();
		q.pop();
		cout << node << " ";
		for(int u : graph[node])
		{
			if(used[u] == false)
			{
				used[u] = true;
				q.push(u);
			}
		}
	}
	
	return ;
}

void dfs(int node)
{
	used[node] = true;
	for(int u : graph[node])
	{
		if(used[u] == false)dfs(u);
	}
}

int components()
{
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(used[i] == false)
		{
			dfs(i);
			ans++;
		}
	}
	return ans;
}

void print_neighbours(int v)
{
	for(int u : graph[v])
	{
		cout << u << " ";
	}	
	cout << endl;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	
	cout << components() << endl;
	return 0;
}

