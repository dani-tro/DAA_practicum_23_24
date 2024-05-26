#include <bits/stdc++.h>

#define MAXN ((unsigned long long)1e5)
#define MAX ((unsigned long long)1e6)

using namespace std;

long long n, m;
long long ans;

vector<pair<int, int>> verts;

struct edge {
    int a, b;

    long long calc_weight() const {
        long long xa = verts[a].first;
        long long ya = verts[a].second;
        long long xb = verts[b].first;
        long long yb = verts[b].second;

        return (xa - xb)* (xa - xb) + (ya - yb)*(ya - yb);
    };

    bool operator<(edge& other) const {
        return calc_weight() < other.calc_weight();
    }

};

vector<edge> edges;


long long par[MAXN], depth[MAXN];

long long find(long long a) {
    if (par[a] == 0) return a;
    return par[a] = find(par[a]);
}

void uni(long long a, long long b) {
    a = find(a);
    b = find(b);

    if (a == b) return;
    if (depth[a] > depth[b]) {
        par[b] = a;
    } else {
        par[a] = b;
        if (depth[a] == depth[b])
            depth[b]++;
    }
}

void kruskal() {
    long long cnt = 0;
    sort(edges.begin(), edges.end());
    for (long long i = 0; i < m, cnt < n - 1; i++) {
        if (find(edges[i].a) == find(edges[i].b))continue;

        uni(edges[i].a, edges[i].b);
        ans += edges[i].calc_weight();
//        pairs.emplace_back(edges[i].a, edges[i].b);
        cnt++;
    }
}

int main() {
    scanf("%lld", &n);
    for (long long i = 0; i < n; ++i) {
        long long x, y;
        scanf("%lld %lld", &x, &y);
//        verts[i].first = x;
//        verts[i].second = y;
        verts.emplace_back(x, y);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
//            m++;
            edges.push_back({i, j});
        }
    }

    kruskal();

    printf("%lld", ans);

    return 0;
}


