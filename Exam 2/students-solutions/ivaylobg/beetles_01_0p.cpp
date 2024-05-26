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

const int MAX = 1e6 + 5;
long long int n, x, y, ans;
struct edge
{
	int s, e;
	long long w;
	bool operator< (const edge& other)
	{
		return w < other.w;
	}
};

std::vector<edge> edges;
std::vector<int> beetles[MAX];
long long int X[MAX];
long long int Y[MAX];

int parent[MAX];
int rank[MAX];

long long int calc(int i, int j)
{
	return (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
}
int find(int a)
{
	if (parent[a] == a) return a;
	else
	{
		return find(parent[a]);
	}
}
void Union(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b) return;
	if (rank[a] > rank[b])
	{
		parent[b] = a;
	}
	else
	{
		parent[a] = b;
		if (rank[a] == rank[b]) rank[b]++;
	}
}

void Kruskal()
{
	//направи разбиването
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
	//сортирай ребрата по тегла
	std::sort(edges.begin(), edges.end());
	//ще представим дървото не с множество от ребра А, а с parent[MAX]
	int br = 0, idx = 0;
	while (br < n - 1)
	{
		if (find(edges[idx].s) != find(edges[idx].e))
		{
			Union(edges[idx].s, edges[idx].e);
			ans += edges[idx].w;

			//std::cout << edges[idx].s << " " << edges[idx].e << " " << edges[idx].w << "\n";

			br++;
		}
		idx++;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	//Collect beetles
	std::cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		std::cin >> x >> y;
		X[i] = x;
		Y[i] = y;
		beetles[x].push_back(i);
	}
	//Create edges
	for (int i = 0; i < MAX; i++)
	{
		if (beetles[i].empty()) continue;

		for (int bi : beetles[i])
		{
			for (int bj : beetles[i])
			{
				if (bi == bj) continue;
				edges.push_back({ bi,bj, calc(bi,bj) });
				//edges.push_back({ bj,bi, calc(bj,bi) });
			}
		}

		for (int j = i+1; j < MAX; j++)
		{
			if (beetles[j].empty()) continue;

			for (int bi : beetles[i])
			{
				for (int bj : beetles[j])
				{
					edges.push_back({ bi,bj, calc(bi,bj)});
					//edges.push_back({ bj,bi, calc(bj,bi) });
				}
			}
			break;
		}
	}

	Kruskal();
	std::cout << ans << "\n";
}