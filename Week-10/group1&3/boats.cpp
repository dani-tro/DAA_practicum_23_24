#include <bits/stdc++.h>

using namespace std;

#define MAX 1100

int n, m, k, par[MAX], depth[MAX], ans[10100];

pair<int, int> queries[10100];

struct edge
{
	int a, b, c;
	bool operator<(const edge& other)
	{
		return c < other.c;
	}
}edges[101000];

int find(int v)
{
	if(par[v] == 0)return v;
	return par[v] = find(par[v]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a == b)return;
	if(depth[a] > depth[b])
	{
		par[b] = a;
	}
	else
	{
		par[a] = b;
		if(depth[a] == depth[b])depth[b]++;
	}
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> k;
	
	for(int i = 0; i < m; i++)
	{
		cin >> edges[i].a >> edges[i].b >> edges[i].c;
	}
	sort(edges, edges + m);
	
	for(int i = 0; i < k; i++)cin >> queries[i].first >> queries[i].second;
	
	
	for(int i = m - 1; i >= 0; i--)
	{
		if(find(edges[i].a) == find(edges[i].b))continue;
		uni(edges[i].a, edges[i].b);
		for(int j = 0; j < k; j++)
		{
			if(ans[j] == 0 && find(queries[j].first) == find(queries[j].second))
			{
				ans[j] = edges[i].c;
			}
		}
	}
	for(int i = 0; i < k; i++)cout << ans[i] << "\n";
	return 0;
}

/*

6 9 4
1 2 2
1 4 3
1 6 1
2 3 3
2 5 2
3 4 4
3 6 2
4 5 5
5 6 4
2 6
3 5
1 2
4 6 

*/
