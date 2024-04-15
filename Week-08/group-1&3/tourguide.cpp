#include <bits/stdc++.h>

using namespace std;

#define MAX 100024

vector<pair<int, int> > gr[MAX];

bool used[MAX];

int d[MAX];

priority_queue<pair<int, int> > pq;

int n, m, k, q, a, b, c, start;

void dijkstra(int from)
{
	fill(d, d + n + 2, INT_MAX);
	d[from] = 0;
	pq.push({d[from], from});
	int node, u, w;
	
	while(!pq.empty())
	{
		node = pq.top().second;
		pq.pop();
		if(used[node])continue;
		used[node] = true;
		
		for(auto p : gr[node])
		{
			u = p.first;
			w = p.second;
			if(d[u] > d[node] + w)
			{
				d[u] = d[node] + w;
				pq.push({-d[u], u});
			}
		}
	}
	return ;
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
		gr[a].push_back({b, c});
		gr[b].push_back({a, c});
	}
	
	cin >> k;
	for(int i = 0; i < k; i++)
	{
		cin >> a;
		gr[n].push_back({a, 0});
	}
	
	dijkstra(n);
	
	
	cin >> 	q;
	for(int i = 0; i < q; i++)
	{
		cin >> a;
		cout << d[a] << endl;
	}
	
	return 0;
}
