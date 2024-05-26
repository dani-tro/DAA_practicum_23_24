#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

#define MAXN 100100
// #define MAXM 1100

void fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

struct beetle
{
    long long x;
    long long y;

    bool operator<(const beetle& other) const
    {
        return x < other.x;
    }
};

struct edge
{
    long long u;
    long long v;

    long long w;

    bool operator<(const edge& other) const
    {
        return w < other.w;
    }
};

long long n, x, y;
vector<beetle> bs;

vector<edge> edges;

long long par[MAXN], d[MAXN];

long long find(long long a) {
    return par[a] == 0 ? a : par[a] = find(par[a]);
}

void uni(long long a, long long b) {
    a = find(a);
    b = find(b);

    if(a == b) return;

    if(d[a] > d[b]) {
        par[b] = a;
    }
    else {
        par[a] = b;
        if(d[a] == d[b]) d[b]++;
    }
}

long long sum;

int main()
{
    fast_IO();

    cin >> n;
    for(long long i = 0; i < n; i++) {
        cin >> x >> y;

        bs.push_back({ x, y });
    }

    //sort(bs.begin(), bs.end());

    for(long long i = 0; i < bs.size(); i++) {
        for(long long j = 1; j < bs.size(); j++) {
            edges.push_back({ i, j, (bs[i].x - bs[j].x)*(bs[i].x - bs[j].x) + (bs[i].y - bs[j].y)*(bs[i].y - bs[j].y) });
        }
    }
    sort(edges.begin(), edges.end());

    for(long long i = 0; i < edges.size(); i++) {
        if(find(edges[i].u) != find(edges[i].v)) {
            //cout << "(" << edges[i].u << ", " << edges[i].v << ")\n";
            sum += edges[i].w;
            uni(edges[i].u, edges[i].v);
        }
    }

    cout << sum << endl;

    return 0;
}