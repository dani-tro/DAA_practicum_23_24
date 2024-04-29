#include <bits/stdc++.h>

using namespace std;

#define MAX 101000

int n, m, a, b, c, par[MAX], d[MAX], ans;

struct edge
{
	int a, b, c;
	bool operator<(const edge& other)
	{
		return c < other.c;
	}
};

vector<edge> edges;

int find(int a)
{
	if(par[a] == -1)return a;
	return par[a] = find(par[a]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if(d[a] > d[b])
	{
		par[b] = a;
	}
	else
	{
		par[a] = b;
		if(d[a] == d[b])d[b]++;
	}
	return;
}

void Kruskal()
{
	sort(edges.begin(), edges.end());
	
	for(int i = 0; i < m; i++)
	{
		if(find(edges[i].a) != find(edges[i].b))
		{
			ans += edges[i].c;
			cout << edges[i].a << " " << edges[i].b << " " << edges[i].c << endl;
			uni(edges[i].a, edges[i].b);
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	fill(par, par + n + 1, -1);
	
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		edges.push_back({a, b, c});
	}
	
	cout << "================" << endl;
	
	Kruskal();
	
	cout << ans << endl;
	
	return 0;
}
