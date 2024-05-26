#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100

struct beetle
{
    pair<int, int> coords;
    int idx;

    beetle() : coords({0, 0}), idx(0) {}
    beetle(pair<int, int> _coords, int _idx) : coords(_coords), idx(_idx) {}

    bool operator!=(const beetle &other)
    {
        return idx != other.idx;
    }
};

struct edge
{
    beetle a, b;
    long long c;

    edge(beetle _a, beetle _b, long long _c) : a(_a), b(_b), c(_c) {}

    bool operator<(const edge &other)
    {
        return c < other.c;
    }
};

int n;
long long ans = 0;
vector<edge> edges;
vector<beetle> beetles;
int par[MAXN];
int d[MAXN];

long long calc(beetle a, beetle b)
{
    return (a.coords.first - b.coords.first) * (a.coords.first - b.coords.first) +
           (a.coords.second - b.coords.second) * (a.coords.second - b.coords.second);
}

int find(int a)
{
    if (par[a] == -1)
        return a;
    return par[a] = find(par[a]);
}

void uni(beetle a, beetle b)
{
    int idxa = find(a.idx);
    int idxb = find(b.idx);
    if (d[idxa] > d[idxb])
    {
        par[idxb] = idxa;
    }
    else
    {
        par[idxa] = idxb;
        if (d[idxa] == d[idxb])
            d[idxb]++;
    }
}

void kruskal()
{
    sort(edges.begin(), edges.end());

    fill(par, par + n, -1);

    for (auto e : edges)
    {
        if (find(e.a.idx) == find(e.b.idx))
            continue;

        ans += e.c;
        uni(e.a, e.b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
    cin >> n;

    int i, u, v;

    for (i = 0; i < n; ++i)
    {
        cin >> u >> v;

        beetle be{{u, v}, i};
        beetles.push_back(be);

        for (auto b : beetles)
        {
            if (b != be)
                edges.push_back({be, b, calc(be, b)});
        }
    }

    kruskal();

    cout << ans << endl;
}