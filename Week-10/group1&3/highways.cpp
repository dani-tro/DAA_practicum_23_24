#include <bits/stdc++.h>

using namespace std;

#define MAX 51000

int n, m, k, par[MAX], sz[MAX], ans, a, b, c;

bool used[MAX];

vector<pair<int, int> > v;

int find(int a)
{
	if(par[a] == 0)return a;
	return par[a] = find(par[a]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a == b)return ;
	if(sz[a] < sz[b])
	{
		sz[b] += sz[a];
		par[a] = b;
	}
	else
	{
		sz[a] += sz[b];
		par[b] = a;
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
		if(c == 0)uni(a, b);
		else
		{
			v.push_back({a, b});
		}
	}
	
	for(int i = 0; i < v.size(); i++)
	{
		if(find(v[i].first) != find(v[i].second))
		{
			uni(v[i].first, v[i].second);
			ans++;
		}
	}
	
	cout << ans << endl;
	return 0;
}

/*

9 12
1 2 0
2 3 0
4 5 1
5 6 1
4 8 0
8 9 0
1 4 0
4 7 0
2 5 1
5 8 1
3 6 0
6 9 0

*/
