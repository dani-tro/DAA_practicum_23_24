#include <bits/stdc++.h>

using namespace std;

#define MAX 101000

long long n, ans, d[MAX], par[MAX];

pair<long long, long long> p[MAX];

struct edge
{
	long long a, b, c;
	
	bool operator<(const edge& other)
	{
		return c < other.c;
	}
};

vector<edge> edges;

long long dist(int i, int j)
{
	return (p[i].first - p[j].first) * (p[i].first - p[j].first) +
	 	   (p[i].second - p[j].second) * (p[i].second - p[j].second);
}

int find(int a)
{
	if(par[a] == 0)return a;
	return par[a] = find(par[a]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if(d[a] > d[b])par[b] = a;
	else
	{
		par[a] = b;
		if(d[a] == d[b])d[b]++;
	}
	return;
}

void kruskal()
{
	sort(edges.begin(), edges.end());
	for(edge e : edges)
	{
		if(find(e.a) != find(e.b))
		{
			ans += e.c;
			uni(e.a, e.b);
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ofstream file, file1;
	file.open ("12.in");
	
	
	cin >> n;
	n = 1000;
	file << "1000" << endl;
	
	for(int i = 0; i < 1000; i++)
	{
		cin >> p[i].first >> p[i].second;
		file << p[i].first << " " << p[i].second << endl;
	}
	
	sort(p, p + n);
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j <= 22; j++)
		{
			if(i + j >= n)break;
			edges.push_back({i, i + j, dist(i, i + j)});
		}
	}
	
	kruskal();
	
	cout << ans << endl;
	file1.open ("12.out");
	file1 << ans << endl;
	return 0;
}
