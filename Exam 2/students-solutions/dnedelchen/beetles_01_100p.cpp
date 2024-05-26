#include <bits/stdc++.h>
#define MAXN 100003
#define MAXY 16
#define endl '\n'
using namespace std;
int n;
typedef long long ll;

struct point
{
    int x, y, idx;
};

struct edge
{
    int from, to;
    ll weight;
    bool operator < (const edge &other) const
    {
        return weight < other.weight;
    }
};

point points[MAXN];
vector<point> points_at[MAXY];
vector<int> adj[MAXN];
vector<edge> edges;

int par[MAXN];
int rk[MAXN];

bool cmp_x(point p1, point p2)
{
    return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

bool cmp_y(point p1, point p2)
{
    return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> points[i].x >> points[i].y;
        points[i].idx = i;
        points_at[points[i].y].push_back(points[i]);
    }
}

ll calc_dist(point p1, point p2)
{
    return 1LL * (p1.x - p2.x) * (p1.x - p2.x) + 1LL * (p1.y - p2.y) * (p1.y - p2.y);
}

int get_par(int v)
{
    if (par[v] == v)
        return v;
    return par[v] = get_par(par[v]);
}

void unite(int u, int v)
{
    u = get_par(u);
    v = get_par(v);
    if (u == v)
        return;

    if (rk[u] <= rk[v])
    {
        par[u] = v;
        if (rk[u] == rk[v])
            ++rk[v];
    }
    else
        par[v] = u;
}

void solve()
{
    for (int i = 0; i < MAXY; ++i)
        sort(points_at[i].begin(), points_at[i].end(), cmp_x);

//    cout << "sorted\n";

    for (int y = 0; y < 12; ++y)
    {
//        cout << "y: " << y << " " << points_at[y].size() << endl;
//        cout << edges.size() << endl;
        if (!points_at[y].size())
        {
//            cout << "skipping \n";
            continue;
        }

        for (int i = 0; i < points_at[y].size(); ++i)
        {
//            cout << "in \n";

            for (int j = 0; j < MAXY; ++j)
            {
                if (y == j || !points_at[j].size())
                    continue;

//                cout << "other y: " << j << endl;

                int l = 0, r = points_at[j].size() - 1, mid;
                int opt = 0;

                while (l <= r)
                {
                    mid = (l + r) >> 1;
//                    cout << l << " " << r << " " << mid << endl;
                    if (points_at[j][mid].x <= points_at[y][i].x)
                    {
                        l = mid + 1;
                        opt = mid;
                    }
                    else
                        r = mid - 1;

                }

                l = opt;
//                cout << "opt " << opt << " " << points_at[j].size() << endl;
//                adj[points_at[y][i].idx].push_back(points_at[j][l].idx);
                edges.push_back({points_at[y][i].idx, points_at[j][l].idx, calc_dist(points_at[y][i], points_at[j][l])});
//                cout << "added \n";
                if (l < points_at[j].size() - 1)
                {
//                    cout << "adding \n";
                    edges.push_back({points_at[y][i].idx, points_at[j][l + 1].idx, calc_dist(points_at[y][i], points_at[j][l + 1])});
                }
//                cout << "**\n";
//                    adj[points_at[y][i].idx].push_back(points_at[j][l + 1]).idx;
            }

            if (i > 0)
                edges.push_back({ points_at[y][i - 1].idx, points_at[y][i].idx, calc_dist(points_at[y][i - 1], points_at[y][i]) });
            if (i < points_at[y].size() - 1)
                edges.push_back({ points_at[y][i].idx, points_at[y][i + 1].idx, calc_dist(points_at[y][i], points_at[y][i + 1]) });
        }

//        cout << "out\n";
    }
//    cout << "sorting edges...\n";
    sort(edges.begin(), edges.end());
    int sz = edges.size();

//    cout << "sorted edges\n";

    for (int i = 0; i < n; ++i)
    {
        par[i] = i;
        rk[i] = 0;
    }

    ll total = 0;
    for (int i = 0; i < sz; ++i)
    {
        if (get_par(edges[i].from) != get_par(edges[i].to))
        {
            unite(edges[i].from, edges[i].to);
            total += edges[i].weight;
        }
    }

    cout << total << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();

    return 0;
}


/**

10
83 10
77 2
93 4
86 6
49 1
62 7
90 3
63 4
40 10
72 0


3
500 1
0 0
1000 0


9
0 0
0 5
0 10
10000 0
10000 5
10000 10
1000000 0
100000 5
100000 10



*/
