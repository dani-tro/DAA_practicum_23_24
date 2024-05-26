#include<iostream>
#include<vector>
#include<queue>
#include<climits>

#define MAXN 10001

using namespace std;

vector<pair<long long, int>> gr[MAXN]; //[v] -> u,w
bool visited[MAXN];
int ds[MAXN];
int important[MAXN];
int hotels[MAXN];
long long n, m,k,q;

priority_queue<pair<long long, int>> pq;

void Krisiig(int start)
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
	long long u, v;
	int w;
	for (size_t i = 0; i < m; i++)
	{
		cin >> u >> v>>w;
		gr[u].push_back({ v,w });
		gr[v].push_back({ u,w });
	}

	fill(ds, ds + n, INT_MAX / 2);

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