#include <bits/stdc++.h>

#define MAXN ((unsigned long long)1e5)
#define MAX ((unsigned long long)1e6)

using namespace std;

int n, m;
long long ans;

vector<int> gr[MAXN]; // maybe unused
pair<int, int> verts[MAXN];

struct edge {
    int a, b;

    long long calc_weight() const {
        int xa = verts[a].first;
        int ya = verts[a].second;
        int xb = verts[b].first;
        int yb = verts[b].second;

        return (xa - xb)* (xa - xb) + (ya - yb)*(ya - yb);
    };

    bool operator<(edge& other) const {
        return calc_weight() < other.calc_weight();
    }

};

vector<edge> edges;

//bool visited[MAXN];
vector<pair<int, int>> pairs;

int par[MAXN], depth[MAXN];

int find(int a) {
    if (par[a] == 0) return a;
    return par[a] = find(par[a]);
}

void uni(int a, int b) {
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
    int cnt = 0;
    sort(edges.begin(), edges.end());
    for (int i = 0; i < m, cnt < n - 1; i++) {
        if (find(edges[i].a) == find(edges[i].b))continue;

        uni(edges[i].a, edges[i].b);
        ans += edges[i].calc_weight();
        pairs.emplace_back(edges[i].a, edges[i].b);
        cnt++;
    }
}

int main() {
    scanf("%i", &n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%i %i", &x, &y);
        verts[i].first = x;
        verts[i].second = y;
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


