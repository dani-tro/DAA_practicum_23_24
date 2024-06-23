#include <bits/stdc++.h>

using namespace std;

#define MAXN 156

#define MAXV 512

#define MAX 80100

#define PA pair<double, int>

int n, m, s, a, b, v, l, par[MAX];

bool used[MAX];

double dist[MAX];

vector<pair<int, double> > gr[MAX];

stack<int> ans;

int encode(int node, int v)
{
	return node * MAXV + v;
}

int decode_node(int code)
{
	return code / MAXV;
}

void dijkstra(int node)
{
	fill(dist, dist + MAX, INT_MAX);
	priority_queue<PA, vector<PA>, greater<PA> > pq;
	pq.push({0.0, node});
	dist[node] = true;
	
	while(!pq.empty())
	{
		node = pq.top().second;
		pq.pop();
		if(used[node])continue;
		used[node] = true;
		
		for(pair<int, double> p : gr[node])
		{
			if(dist[p.first] > dist[node] + p.second)
			{
				dist[p.first] = dist[node] + p.second;
				par[p.first] = node;
				pq.push({dist[p.first], p.first});
			}
		}
	}
	return;
}

void restore_answer()
{
	int node = par[MAX - 1];
	while(node != 0)
	{
		ans.push(decode_node(node));
		node = par[node];
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> s;
	
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> v >> l;
		if(v != 0)
		{
			for(int t = 1; t < 501; t++)
			{
				gr[encode(a, t)].push_back({encode(b, v), l * (1.0 / v)});
			}
		}
		else
		{
			for(int t = 1; t < 501; t++)
			{
				gr[encode(a, t)].push_back({encode(b, t), l * (1.0 / t)});
			}
		}
	}
	
	for(int t = 1; t <= 500; t++)gr[encode(s, t)].push_back({MAX - 1, 0.0});
	dijkstra(encode(0, 70));
	
	restore_answer();
	
	while(!ans.empty())
	{
		cout << ans.top() << " ";
		ans.pop();
	}
	
	cout << endl;
	
	return 0;
}

