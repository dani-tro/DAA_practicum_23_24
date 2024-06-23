#include <bits/stdc++.h>

using namespace std;

#define MAX 10001000

int n, a[MAX], repres[MAX], erat[MAX], dv, ans, br;

bool used[MAX];

vector<int> gr[MAX / 8];

void calc_erat()
{
	br = n + 1;
	for(long long i = 2; i < MAX; i++)
	{
		if(erat[i] == 0)
		{
			repres[i] = br++;
			erat[i] = i;
			for(long long j = i * i; j < MAX; j += i)erat[j] = i;
		}	
	}
	
	return;
}

void dfs(int node)
{
	used[node] = true;
	for(int v : gr[node])
	{
		if(!used[v])dfs(v);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	calc_erat();
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		while(a[i] != 1)
		{
			dv = erat[a[i]];
			gr[i].push_back(repres[dv]);
			gr[repres[dv]].push_back(i);
			a[i] /= dv;
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(!used[i])
		{
			dfs(i);
			ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
