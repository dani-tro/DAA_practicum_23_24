#include <bits/stdc++.h>

using namespace std;

#define MAX 100100

int n, m, q, d[MAX], par[MAX], sz[MAX], a, b, t, compcnt, mx;

int find(int a)
{
	if(par[a] == -1) return a;
	return par[a] = find(par[a]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	
	if(a == b)return;
	compcnt--;
	
	if(d[a] > d[b])
	{
		par[b] = a;
		sz[a] += sz[b];
		mx = max(mx, sz[a]);
	}
	else if(d[a] < d[b])
	{
		par[a] = b;
		sz[b] += sz[a];
		mx = max(mx, sz[b]);
	}
	else
	{
		par[a] = b;
		d[b]++;
		sz[b] += sz[a];
		mx = max(mx, sz[b]);
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
	fill(sz, sz + n + 1, 1);
	mx = 1;
	compcnt = n;
	
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		uni(a, b);
		cout << compcnt << " " << mx << endl;
	}
	
	return 0;
}
