#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const unsigned long long int MAXN = 1e5+5;
unsigned long long int n;
struct point
{
    unsigned long long int x, y;
} pts[MAXN];
struct edge
{
    unsigned long long int from, to;
    unsigned long long int w;
    bool operator < (const edge& o) const
    {
        return w < o.w;
    }
};
vector<edge> g;
unsigned long long int par[MAXN], d[MAXN];

unsigned long long int find_rec(unsigned long long int u)
{
    if (par[u] == 0)
        return u;
    return par[u] = find_rec(par[u]);
}

void uni(unsigned long long int u, unsigned long long int v)
{
    u = find_rec(u);
    v = find_rec(v);

    if (u == v) return;
    
    if (d[u] > d[v])
    {
        par[v] = u;
    }
    else
    {
        par[u] = v;
        if (d[u] == d[v]) ++d[v];
    }
}

unsigned long long int dist(point a, point b)
{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int main()
{
    cin >> n;
    for (unsigned long long int i = 0; i < n; ++i)
    {
        cin >> pts[i].x >> pts[i].y;
    }
    for (unsigned long long int i = 0; i < n; ++i)
    {
        for (unsigned long long int j = i + 1; j < n; ++j)
        {
            g.push_back({i,j,dist(pts[i],pts[j])});
        }
    }
    sort(g.begin(), g.end());

    unsigned long long int ans = 0;

    for (unsigned long long int i = 0; i < g.size(); ++i)
    {
        if (find_rec(g[i].from) != find_rec(g[i].to))
        {
            uni(g[i].from, g[i].to);
            ans += g[i].w;
        }
    }
    cout << ans << endl;
    return 0;
}