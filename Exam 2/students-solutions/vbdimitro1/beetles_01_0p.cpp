#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <tuple>

using namespace std;

const int MAXN = 100000;

struct coord
{
	int x;
	int y;

	coord(int newX, int newY)
	{
		x = newX;
		y = newY;
	}

	coord()
	{
		x = 0;
		y = 0;
	}

	bool operator<(const coord& other)const
	{
		return x > other.x;
	}
};

const int MAXX = 1000000;
const int MAXY = 10;

coord parent[MAXX][MAXY];
int sz[MAXX][MAXY];

void make_set(int x, int y)
{
	parent[x][y] = { x,y };
	sz[x][y] = 1;
}

coord find_set(int x, int y)
{
	if (parent[x][y].x == x && parent[x][y].y == y)
		return parent[x][y];

	return parent[x][y] = find_set(parent[x][y].x, parent[x][y].y);
}

void union_sets(int x1, int y1, int x2, int y2)
{
	x1 = find_set(x1, y1).x;
	y1 = find_set(x1, y1).y;
	x2 = find_set(x2, y2).x;
	x2 = find_set(x2, y2).y;

	if (x1 == x2 && y1 == y2)
	{
		return;
	}

	if (sz[x1][y1] < sz[x2][y2])
	{
		swap(x1, x2);
		swap(y1, y2);
	}

	parent[x2][y2].x = x1;
	parent[x2][y2].y = y1;

	sz[x1][y1] += sz[x2][y2];
}


int main()
{
	int N;

	cin >> N;

	vector<coord> b;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		make_set(x, y);

		b.push_back({ x,y });
	}

	priority_queue<tuple<int, coord, coord>> pq;

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			int distance = (b[i].x - b[j].x) * (b[i].x - b[j].x) + (b[i].y - b[j].y) * (b[i].y - b[j].y);

			pq.push({ -distance, {b[i].x, b[i].y}, {b[j].x, b[j].y} });
		}
	}

	int cnt = 1;
	long long sum = 0;

	while (cnt < N && !pq.empty())
	{
		int w;
		coord u, v;
		tie(w, u, v) = pq.top();
		pq.pop();
		w = -w;

		if (find_set(u.x, u.y).x == find_set(v.x, v.y).x && find_set(u.x, u.y).y == find_set(v.x, v.y).y)
			continue;

		cnt++;
		union_sets(u.x, u.y, v.x, v.y);
		sum += w;
	}

	cout << sum;

	return 0;
}