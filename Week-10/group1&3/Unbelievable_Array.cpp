#include <bits/stdc++.h>

using namespace std;

#define MAX 100100

int n, m, a[MAX], t, x, y, repres[MAX], d[MAX], par[MAX], br, col, tmp;

int find(int a)
{
	if(par[a] == -1)return a;
	return par[a] = find(par[a]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a == b)return ;
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
void solve(int z)
{
	fill(par, par + MAX, -1);
	fill(d, d + MAX, 0);
	fill(repres, repres + MAX, 0);
	
	cout << "Case " << z << ":"  << endl;
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(repres[a[i]] == 0)repres[a[i]] = i;
		uni(repres[a[i]], i);
	}
	
	br = n + 1;
	for(int i = 0; i < m; i++)
	{
		cin >> t;
		if(t == 1) 
		{
			cin >> x >> y;
			col = y;
			tmp = x;
			if(repres[x] == 0)continue;
			
			x = repres[x];
			repres[tmp] = 0;
			if(repres[y] == 0)repres[y] = br++;
			y = repres[y];
			uni(x, y);
			a[find(x)] = col;
		}
		else
		{
			cin >> x;
			cout << a[find(x)] << endl;
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)solve(i);
	
	return 0;
}
