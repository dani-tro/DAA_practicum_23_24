#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
#include<cmath>

using namespace std;

#define MAXN 1000001


unsigned long long n, d[MAXN], par[MAXN], ans;
unsigned long long visited[MAXN];

struct edge
{
    unsigned long long x, y, w;

    bool operator<(const edge& other)
    {
        return w < other.w;
    }
} es[MAXN];

struct node
{
    unsigned long long x;
    int y;

} ns[MAXN];

int find(unsigned long long x)
{
    if (par[x] == 0)return x;
    return par[x] = find(par[x]);
}

void uni(unsigned long long a, unsigned long long b)
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
        if (d[a] == d[b])
        {
            d[b]++;
        }
    }
    return;
}

unsigned long long calculateDist(unsigned long long i, unsigned long long j)
{
    return ((ns[i].x - ns[j].x) * (ns[i].x - ns[j].x)) + ((ns[i].y - ns[j].y) * (ns[i].y - ns[j].y));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (unsigned long long i = 0; i < n; i++)
    {
        cin >> ns[i].x >> ns[i].y;

    }
    unsigned long long ecount = 0;

    for (unsigned long long i = 0; i < n - 1; i++)
    {
        if (visited[i])
        {
            continue;
        }
        visited[i] = true;
        for (unsigned long long j = i + 1; j < n; j++)
        {
            es[ecount].x = i;
            es[ecount].y = j;
            es[ecount].w = calculateDist(i, j);
            ecount++;
        }
    }
    sort(es, es + ecount);

    for (unsigned long long i = 0; i < ecount; i++)
    {
        if (find(es[i].x) != find(es[i].y))
        {
            uni(es[i].x, es[i].y);
            ans += es[i].w;
        }
    }

    cout << ans;
    return 0;
}