//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct pos
{
	int x, y;

	bool operator==(const pos& other) const
	{
		return x == other.x && y == other.y;
	}
};

int n;
vector<pos> places;

struct edge
{
	pos u = { 0,0 }, v = { 0, 0 };
	int e = dist(u,v);

	int dist(const pos& temp, const pos& other) const
	{
		return (temp.x - other.x) * (temp.x - other.x) + (temp.y - other.y) * (temp.y - other.y);
	}
	bool operator < (const edge& other) const
	{
		return e > other.e;
	}
};

priority_queue<edge> pq;
int sum = 0;

void getEdges()
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			pq.push({ places[i], places[j] });
		}
	}
	vector<bool> visited;
	for (int i = 0; i < n; ++i)
	{
		visited.push_back(0);
	}
	int sz = pq.size();
	int check = 0;
	while (!pq.empty())
	{
		++check;
		edge curr = pq.top();
		pq.pop();
		int flag = -1;
		for (int i = 0;i < n; ++i)
		{
			if (places[i] == curr.u)
			{
				if (visited[i]) continue;
			}
			if (places[i] == curr.v)
			{
				if (visited[i]) continue;
			}
		}
		if(check <= sz - 1) sum += curr.e;
	}
	cout << sum;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		places.push_back({ a,b });
	}
	getEdges();
}