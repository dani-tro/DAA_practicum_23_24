#include <bits/stdc++.h>

using namespace std;

#define MAX 1024

vector<int> gr[MAX];

int n, m, q, a, b, cur_component = 1, comp[MAX];

void dfs(int node, int component)
{
	comp[node] = component;
	for(int u : gr[node])
	{
		if(!comp[u])dfs(u, component);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	for(int i = 1; i <= n; i++)
	{
		if(!comp[i])dfs(i, cur_component++);
	}
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		cin >> a >> b;
		cout << (comp[a] == comp[b]);
	}
	cout << endl;
	
	return 0;
}

/*

9 9 
1 2
3 4
5 6
7 8
9 5
7 2
8 2
6 9
1 7
3
1 8
6 2
4 7

*/
