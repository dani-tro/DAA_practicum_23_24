#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
const int MAXN = 100000;
vector<pair<int, int>> gr[MAXN];
vector<int> places;
int d[MAXN];
bool used[MAXN];
priority_queue<pair<int, int>> pq;
int m, n;

void dijkstra(int from)
{
	for (int i = 0; i < n; i++)
	{
		used[i] = false;
	}

	while (!pq.empty())
	{
		pq.pop();
	}
	d[from] = 0;
	pq.push({ 0, from });

	int node, adj, weight;
	while (!pq.empty())
	{
		int node = pq.top().second;
		pq.pop();
		if (used[node]) continue;
		used[node] = true;

		for (auto p : gr[node])
		{
			/*
			for (int i = 0; i < m; i++) cout << d[i] << " ";
			cout << endl;
			*/
			adj = p.first;
			weight = p.second;
			if (d[adj] > d[node] + weight)
			{
				d[adj] = d[node] + weight;
				pq.push({ -weight, adj });
			}
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int x, y, t;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> t;
		gr[x].push_back({ y,t });
		gr[y].push_back({ x,t });
	}

	for (int i = 0; i < n; i++)
	{
		d[i] = INT_MAX / 2;
	}

	int important;
	cin >> important;
	int place;
	for (int i = 0; i < important; i++)
	{
		cin >> place;
		dijkstra(place);
	}

	int calls;
	int start;
	cin >> calls;
	for (int i = 0; i < calls; i++)
	{
		cin >> start;
		cout << d[start] << endl;

	}
}
