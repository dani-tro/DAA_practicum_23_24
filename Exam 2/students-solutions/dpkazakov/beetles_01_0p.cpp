#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

#define MAXN 100001

#define MAXM 200001

long long n, m, d[MAXN], par[MAXN], ans, cnt;
long long visited[MAXN];

struct edge
{
	long long a, b, c;

	bool operator<(const edge& other)
	{
		return c < other.c;
	}
} e[MAXM];

struct node
{
	long long x, y;

} ns[MAXM];

int find(int a)
{
	if (par[a] == 0)return a;
	return par[a] = find(par[a]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);

	cnt--;
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

	cnt = n;

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
			e[ecount].a = i;
			e[ecount].b = j;
			e[ecount].c = calculateDist(i, j);
			ecount++;
		}
	}
	sort(e, e + ecount);

	for (int i = 0; i < ecount; i++)
	{
		if (find(e[i].a) != find(e[i].b))
		{
			uni(e[i].a, e[i].b);
			ans += e[i].c;
		}
	}

	cout << ans << endl;
	return 0;
}
