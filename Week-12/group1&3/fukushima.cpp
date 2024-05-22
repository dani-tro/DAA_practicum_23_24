#include <bits/stdc++.h>

using namespace std;

#define MAX 1024

vector<pair<int, int> > gr[MAX];

int n, m, a, b, c, d[MAX];

bool calc(int x, bool prnt)
{
	fill(d, d + n + 1, 0);
	for(int i = 1; i <= n; i++)
	{
		for(auto p : gr[i])
		{
			if(p.second <= x)d[p.first]++;
		}
	}
	priority_queue<int> pq;
	
	for(int i = 1; i <= n; i++)
	{
		if(d[i] == 0)pq.push(-i);
	}
	
	int cnt = 0;
	
	while(!pq.empty())
	{
		int node = -pq.top();
		pq.pop();
		
		cnt++;
		
		if(prnt)cout << node << " ";
		for(auto p : gr[node])
		{
			if(p.second <= x)
			{
				d[p.first]--;
				if(d[p.first] == 0)pq.push(-p.first);
			}
		}
	}
	
	return (cnt == n);
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		
		gr[b].push_back({a, c});
	}
	
	int l = 0, r = 100005, mid, opt;
	
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(calc(mid, 0))
		{
			l = mid + 1;
			opt = mid;
		}
		else r = mid - 1;
	}
	if(opt == 100005)cout << "-1" << endl;
	else cout << opt << endl;
	
	calc(opt, 1);
	
	return 0;
}
