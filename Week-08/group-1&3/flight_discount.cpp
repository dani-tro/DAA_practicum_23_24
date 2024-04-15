#include <bits/stdc++.h>

using namespace std;

#define MAX 200024

vector<pair<int, int> > gr[MAX];

bool used[MAX];

long long d[MAX];

priority_queue<pair<long long, int> > pq;

int n, m, a, b, c, start;

void dijkstra(int from)
{
	fill(d, d + 2 * n + 2, LLONG_MAX / 2); //for(int i = 0; i < n; i++)d[i] = INT_MAX / 2;
	d[from] = 0;
	pq.push({d[from], from});
	long long node, u, w;
	
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
		gr[a].push_back({b + n, c / 2});
		gr[a + n].push_back({b + n, c});
	}
	
	dijkstra(1);
	
	cout << min(d[n], d[n + n]) << endl;
	
	return 0;
}
