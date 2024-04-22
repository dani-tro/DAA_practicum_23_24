#include <bits/stdc++.h>

using namespace std;

#define MAX 10000

int n, m, q, d[MAX], par[MAX], a, b, t;

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
	
	if(d[a] > d[b])
	{
		par[b] = a;
	}
	else if(d[a] < d[b])
	{
		par[a] = b;
	}
	else
	{
		par[a] = b;
		d[b]++;
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 0; i <= n; i++)par[i] = -1;
	
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		uni(a, b);
	}
	
	cin >> q;
 	
	for(int i = 0; i < q; i++)
	{
		cin >> t >> a >> b;
		if(t == 1)
		{
			if(find(a) == find(b))cout << "1";
			else cout << "0";
		}
		else 
		{
			uni(a, b);
		}
	}
	
	
	return 0;
}
