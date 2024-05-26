#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using edge = pair<long, long>;

vector<vector<edge>> graph;
long closest[100000];

long find_closest_important_place(long src) {
	if (closest[src] != -1)
	{
		return closest[src];
	}

	vector<long> paths(graph.size());
	vector<long> dist(graph.size());
	vector<bool> visited(graph.size());

	for (long i = 0; i < graph.size(); i++)
	{
		paths[i] = -1;
		dist[i] = 100000;
	}

	priority_queue<edge, vector<edge>, greater<edge>> pq;

	dist[src] = 0;
	paths[src] = src;
	pq.push(edge(0, src));

	while (!pq.empty())
	{
		long v = pq.top().second;
		pq.pop();
		
		if (visited[v]) {
			continue;
		}

		if (closest[v] != -1) {
			long c = v;
			while (paths[v] != v)
			{
				closest[paths[v]] = closest[v] + dist[v] - dist[paths[v]];
				v = paths[v];
			}
			return closest[src];
		}
		visited[v] = true;
		for (auto e : graph[v])
		{
			if (dist[e.first] > dist[v] + e.second) {
				dist[e.first] = dist[v] + e.second;
				paths[e.first] = v;
				pq.push(edge(dist[e.first], e.first));
			}
		}
	}
}

int main()
{
    long n, m; cin >> n >> m;
    graph = vector<vector<edge>>(n);

	for (long i = 0; i < n; i++)
	{
		closest[i] = -1;
	}

	for (long i = 0; i < m; i++)
	{
		long from, to, weight;
		cin >> from >> to >> weight;
		graph[from].push_back(edge(to,weight));
		graph[to].push_back(edge(from, weight));
	}

	long k; cin >> k;
	for (long i = 0; i < k; i++)
	{
		long t; cin >> t;
		closest[t] = 0;
	}

	long q; cin >> q;
	for (long i = 0; i < q; i++)
	{
		long t; cin >> t;
		cout << find_closest_important_place(t) << endl;
	}
}