#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

int N, M, K, Q;

const int MAXN = 100000;
const int MAXM = 300000;
const int MAXK = 100000;
const int MAXQ = 100000;

std::vector<std::tuple<int, int>> gr[MAXM];

int d[MAXN];
int special[MAXK];
int questions[MAXQ];

void dijkstra(int start)
{
	std::fill(d, d + N + 1, INT_MAX / 2);

	std::priority_queue<std::tuple<int, int>> pq;
	d[start] = 0;
	pq.push({ d[start], start});

	while (!pq.empty())
	{
		int currentVert = std::get<1>(pq.top());

		pq.pop();

		for (auto p : gr[currentVert])
		{
			int u = std::get<1>(p);
			int w = std::get<0>(p);

			if (d[u] > d[currentVert] + w)
			{
				d[u] = d[currentVert] + w;
				pq.push({ -d[u], u });
			}
		}
	}
}

int main()
{
	std::cin >> N >> M;

	int x, y, t;

	for (int i = 0; i < M; i++)
	{
		std::cin >> x >> y >> t;

		gr[x].push_back({ t, y });
		gr[y].push_back({ t, x });
	}

	std::cin >> K;

	for (int i = 0; i < K; i++)
	{
		std::cin >> special[i];
	}

	std::cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		std::cin >> questions[i];
	}


	for (int i = 0; i < Q; i++)
	{
		dijkstra(questions[i]);

		int closest = special[0];
		for (int j = 1; j < K; j++)
		{
			if (d[special[j]] < d[closest])
			{
				closest = special[j];
			}
		}

		std::cout << d[closest] << std::endl;
	}

	return 0;
}