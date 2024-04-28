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


int N, M, K; double c;
struct segment
{
	int weight;
	int idx, reps;

	bool operator <(segment& other)
	{
		return reps < other.reps;
	}
	void Print()
	{
		std::cout << weight << " " << idx << " " << reps << "\n";
	}
};
bool cmp(segment& s1, segment& s2)
{
	return s1.reps < s2.reps;
}
std::vector<segment> v;
//std::vector<std::pair<int, int>> routes;

int calc(int l, int r)
{
	int ans = 0;
	for (int j = l - 1; j <= r - 1; j++)
	{
		ans += v[j].weight;
	}

	return ans;
}

int main()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> N >> M >> K;
	int w; int l, r;
	for (int i = 0; i < N; i++)
	{
		std::cin >> w; 
		v.push_back({ w,i,0 });
	}
	for (size_t i = 0; i < M; i++)
	{
		std::cin >> l >> r;
		//routes.push_back({ l,r });
		for (int j = l-1; j <= r-1; j++)
		{
			v[j].reps++;
		}
	}

	std::priority_queue<std::pair<int, int>> pq;

	for (segment s : v) pq.push({s.reps,s.idx});

	while (K > 0 && !pq.empty())
	{

		int removed = fmin (v[pq.top().second].weight, K);

		//std::cout << pq.top().first << " " << pq.top().second << " " << K << " " << removed << "\n";

		K -= removed;
		v[pq.top().second].weight -= removed;
		pq.pop();
	}
	int ans = 0;

	for (segment s : v) ans += s.weight * s.reps;

	//for (segment s : v) s.Print();

	std::cout << ans << "\n";
}