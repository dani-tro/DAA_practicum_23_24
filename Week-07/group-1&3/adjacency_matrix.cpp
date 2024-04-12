# include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

bool adj[MAXN][MAXN];

int n, m;

bool used[MAXN];

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
		for(int i = 1; i <= n; i++)
		{
			if(adj[node][i] != 0 && used[i] == false)
			{
				used[i] = true;
				q.push(i);
			}
		}
	}
	
	return ;
}

void dfs(int node)
{
	used[node] = true;
	for(int i = 1; i <= n; i++)
	{
		if(adj[node][i] != 0 && used[i] == false)dfs(i);
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

void print_neighbours (int u)
{
    for (int i = 1; i <= n; i++)
	{
        if (adj[u][i]) cout << i << " ";
    }
    cout << endl;
}

int main()
{
    cin >> n >> m;
    int i, j, u, v;
    for (i = 0; i < m; i++)
	{
        cin >> u >> v;
        adj[u][v] = true;
        adj[v][u] = true; //undirected
    }
    cout << components() << endl;
}
