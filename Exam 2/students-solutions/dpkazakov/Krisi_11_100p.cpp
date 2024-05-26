#include<iostream>
#include<vector>
#include<queue>
#include<climits>

#define MAXN 110000

using namespace std;

vector<pair<long, long>> gr[MAXN]; //[v] -> u,w
bool visited[MAXN];
long ds[MAXN];
long important[MAXN];
long hotels[MAXN];
long n, m,k,q;

priority_queue<pair<long, long>> pq;

void Krisiig(long start)
{
	ds[start] = 0;
	pq.push({ ds[start],start });

	while (!pq.empty())
	{
		int node = pq.top().second;
		pq.pop();
		if (visited[node])
		{
			continue;
		}
		visited[node] = true;
		for (auto v : gr[node])
		{
			int u = v.first;
			int w = v.second;
			if (ds[u] > ds[node] + w)
			{
				ds[u] = ds[node] + w;
				pq.push({ -ds[u],u });
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	long u, v;
	long w;
	for (size_t i = 0; i < m; i++)
	{
		cin >> u >> v>>w;
		gr[u].push_back({ v,w });
		gr[v].push_back({ u,w });
	}

	fill(ds, ds + n, INT_MAX);

	cin >> k;
	for (size_t i = 0; i < k; i++)
	{
		fill(visited, visited + n, false);
		cin >> u;
		Krisiig(u);
	}

	cin >> q;
	for (size_t i = 0; i < q; i++)
	{
		cin >> u;
		cout << ds[u] << endl;

	}
}