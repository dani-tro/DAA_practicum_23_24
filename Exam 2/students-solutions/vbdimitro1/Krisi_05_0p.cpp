#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 100005;

int d[MAX];

vector<pair<int, int>> graph[MAX];

bool used[MAX];

int N, M, K, Q;

void Dijkstra(int start)
{
	//	fill(d, d + N, INT_MAX);
	//	fill(used, used + N, false);

	for (int i = 0; i < N; i++)
	{
		used[i] = false;
		d[i] = INT_MAX;
	}

	priority_queue<pair<int, int>> pq;

	d[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int node = pq.top().second;
		pq.pop();

		if (used[node])
			continue;
		used[node] = true;

		for (auto edge : graph[node])
		{
			int to = edge.first;
			int w = edge.second;

			if (d[to] > d[node] + w)
			{
				d[to] = d[node] + w;
				pq.push({ d[to], to });
			}
		}

	}

}


int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int v, u, w;

		cin >> v >> u >> w;

		graph[v].push_back({ u, w });
		graph[u].push_back({ v, w });
	}

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int s;

		cin >> s;

		graph[N].push_back({ s, 0 });
	}

	Dijkstra(N);

	cin >> Q;

	vector<int> ans;

	for (int i = 0; i < Q; i++)
	{
		int q;

		cin >> q;

		ans.push_back(d[q]);
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';


	return 0;
}