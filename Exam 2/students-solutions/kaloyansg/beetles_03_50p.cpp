#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, par[100005], dist[100005], ans;

struct edge
{
    long long u, v, w;

    bool operator<(const edge& other)
    {
        return this->w < other.w;
    }

};
vector<edge> edges;

long long find(long long u)
{
    if (par[u] == 0)////////////////////////////////////////////////////////////////////////////////////////////
        return u;
    return par[u] = find(par[u]);
}

void uni(long long u, long long v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return;

    if (dist[u] < dist[v])
    {
        par[u] = v;
    }
    else
    {
        if (dist[u] == dist[v])
        {
            dist[u]++;
        }
        par[v] = u;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<pair<long long, long long>> brunburi;
    long long x,y;
    long long distance, purvo, vtoro;


    for (long long i = 0; i < n; ++i)
    {
        cin >> x >> y;
        brunburi.push_back({ x,y });
    }

    for (long long i = 0; i < n; i++)
    {
        for (long long j = i+1; j < n; j++)
        {
            purvo = (brunburi[i].first - brunburi[j].first) * (brunburi[i].first - brunburi[j].first);
            vtoro = (brunburi[i].second - brunburi[j].second) * (brunburi[i].second - brunburi[j].second);
            distance = purvo + vtoro;
            edges.push_back({ i+1,j+1, distance });///////////////////////////////////////////////////////
        }
    }

    sort(edges.begin(), edges.end());

    //fill(par, par + n, -1);///////////////////////////////////////////////////////////////////////////////////

    long long sizee = edges.size();

    long long cnt = 0;

    for (long long i = 0; i < sizee; ++i)
    {
        if (find(edges[i].u) != find(edges[i].v))
        {
            uni(edges[i].u, edges[i].v);
            ans += edges[i].w;
            cnt++;
        }
        else if (cnt == n - 1)
            break;
    }

    cout << ans;
}