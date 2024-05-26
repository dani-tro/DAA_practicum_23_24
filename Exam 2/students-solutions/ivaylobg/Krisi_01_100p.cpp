#include <iostream>
#include <stdio.h>
#include <stack>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <queue>
#include <climits>

const int MAX = 1e5 + 5;
int n, m, k, q, u, v, w;
std::vector<std::pair<int, int>> adj[MAX];
int d[MAX];
int par[MAX];
bool used[MAX];
std::priority_queue<std::pair<int, int>> pq;

void Dijkstra(int s)
{
	for (int i = 0; i <= n; i++)
	{
		d[i] = INT_MAX / 2;
		par[i] = -1;
		used[i] = 0;
	}
	d[s] = 0;
	pq.push({d[s],s});
	while (!pq.empty())
	{
		int x = pq.top().second; pq.pop();
		if (used[x]) continue;
		used[x] = 1;
		for (auto p : adj[x])
		{
			int y = p.first;
			int weight = p.second;
			if (d[y] > d[x] + weight)
			{
				d[y] = d[x] + weight;
				par[y] = x;
				pq.push({-d[y], y});
			}
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n >> m;
	for (size_t i = 0; i < m; i++)
	{
		std::cin >> u >> v >> w;
		u++; v++;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w });
	}
	std::cin >> k;
	for (size_t i = 0; i < k; i++)
	{
		std::cin >> u; u++;
		adj[u].push_back({ 0,0 });
		adj[0].push_back({ u,0 });
	}
	Dijkstra(0);
	std::cin >> q;
	std::vector<int> ans;
	for (size_t i = 0; i < q; i++)
	{
		int a;
		std::cin >> a;
		a++;
		ans.push_back(d[a]);
	}
	for (int x : ans)
	{
		std::cout << x << "\n";
	}
	/*for (size_t i = 0; i <= n; i++)
	{
		std::cout << i << " | " << d[i] << "\n";
	}*/
}