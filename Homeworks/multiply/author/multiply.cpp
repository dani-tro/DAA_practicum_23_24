#include <bits/stdc++.h>

using namespace std;

#define MAX 11000000

int n, a[MAX], repres[MAX], erat[MAX], dv, ans, par[MAX], d[MAX];

bool used[MAX];

void calc_erat()
{
	for(long long i = 2; i < MAX; i++)
	{
		if(erat[i] == 0)
		{
			erat[i] = i;
			for(long long j = i * i; j < MAX; j += i)erat[j] = i;
		}	
	}
	return;
}

int find(int a)
{
	if(par[a] == 0)return a;
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
	
	calc_erat();
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		while(a[i] != 1)
		{
			dv = erat[a[i]];
			if(repres[dv] == 0)
			{
				repres[dv] = i;
			}
			uni(repres[dv], i);
			a[i] /= dv;
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		used[find(i)] = 1;
	}
	
	for(int i = 1; i <= n; i++)ans += used[i];
	
	cout << ans << endl;
	
	return 0;
}
