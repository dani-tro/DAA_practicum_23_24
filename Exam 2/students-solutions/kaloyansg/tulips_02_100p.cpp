#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#define MAX 1001000

long long m, n, k;
vector<long long> g[MAX];
int visited[MAX];

void dfs(long long u)
{
	//cout << u << " ";
	visited[u] *= -1;
	for (auto v : g[u])
	{
		if (visited[v] < 0 && abs(visited[v]) == abs(visited[u]))
			dfs(v);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a;

	cin >> n >> m;
	for (size_t i = 1; i <= n; ++i)
	{
		for (size_t j = 1; j <= m; ++j)
		{
			cin >> a;
			visited[(i - 1) * m + j] = -a;
		}
	}

	long long nodes = m * n;

	for (long long i = 1; i <= nodes; ++i)
	{
		if (i % m != 0)
			g[i].push_back(i + 1);
		if (i <= (nodes - m))
			g[i].push_back(i + m);
		if (i % m != 1)
			g[i].push_back(i - 1);
		if (i > m)
			g[i].push_back(i - m);
	}

	long long counter = 0;

	for (long long i = 1; i <= nodes; i++)
	{
		if (visited[i] < 0)
		{
			dfs(i);
			counter++;
		}
	}

	cout << counter;
}