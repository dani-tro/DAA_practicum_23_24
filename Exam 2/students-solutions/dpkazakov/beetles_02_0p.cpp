#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
#include<cmath>

using namespace std;

#define MAXN 100001

#define MAXM 200001

long long n, m, d[MAXN], par[MAXN], ans;
long long visited[MAXN];

struct edge
{
	long long x, y, w;

	bool operator<(const edge& other)
	{
		return w < other.w;
	}
} es[MAXM];

struct node
{
	long long x, y;

} ns[MAXM];

int find(int x)
{
	if (par[x] == 0)return x;
	return par[x] = find(par[x]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);

	if (d[a] > d[b])
	{
		par[b] = a;
	}
	else
	{
		par[a] = b;
		if (d[a] == d[b])d[b]++;
	}
	return;
}

long long calculateDist(long long i, long long j)
{
	return pow((ns[i].x - ns[j].x),2) + pow((ns[i].y - ns[j].y), 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> ns[i].x >> ns[i].y;

	}
	int ecount = 0;

	for (int i = 0; i < n-1; i++)
	{
		if (visited[i])
		{
			continue;
		}
		visited[i] = true;
		for (int j = i + 1; j < n; j++)
		{
			es[ecount].x = i;
			es[ecount].y = j;
			es[ecount].w = calculateDist(i, j);
			ecount++;
		}
	}
	sort(es, es + ecount);

	for (int i = 0; i < ecount; i++)
	{
		if (find(es[i].x) != find(es[i].y))
		{
			uni(es[i].x, es[i].y);
			ans += es[i].w;
		}
	}

	cout << ans << endl;
	return 0;
}
