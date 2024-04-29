#include <bits/stdc++.h>

using namespace std;

#define MAX 101000

int n, m, a, b, c, par[MAX], d[MAX], ans = INT_MAX, l, r, cnt;

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
	cnt++;
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		edges.push_back({a, b, c});
	}
	
	sort(edges.begin(), edges.end());
	
	for(int i = 0; i < m; i++)
	{
		fill(par, par + n + 1, -1);
		fill(d, d + n + 1, 0);
		cnt = 0;
		
		for(int j = i; j < m; j++)
		{
			if(find(edges[j].a) != find(edges[j].b))
			{
				uni(edges[j].a, edges[j].b);
			}
			if(cnt == n - 1)
			{
				if(ans > edges[j].c - edges[i].c)
				{
					ans = edges[j].c - edges[i].c;
					l = edges[i].c;
					r = edges[j].c;
				}
				break;
			}
		}
	}
	
	cout << l << " " << r << endl;
 	
	return 0;
}
