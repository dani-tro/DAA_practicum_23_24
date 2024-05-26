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

    bool operator<(const edge& other) const {
        return calc_weight() > other.calc_weight();
    }

};


bool visited[MAXN];
priority_queue<edge> pq;

//vector<edge> ansp;

void prim(int s) {
    visited[s] = true;
    for (int i = 0; i < n; ++i) {
        if (i != s) {
            pq.push({s, i});
        }
    }

    while (!pq.empty()) {
        auto curr_ed = pq.top();
        pq.pop();
        if (visited[curr_ed.b]) continue;
//        ansp.push_back(curr_ed);
        ans += curr_ed.calc_weight();
        long long to = curr_ed.b;
        visited[to] = true;
//        for (auto u: g[to]) pq.push(u);
        for (int i = 0; i < n; ++i) {
            if (i != to && curr_ed.b != i)
                pq.push({curr_ed.b, i});
        }
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

//    for (int i = 0; i < n; ++i) {
//        for (int j = i+1; j < n; ++j) {
////            m++;
//            edges.push_back({i, j});
//        }
//    }
//
//    kruskal();

    prim(0);

    printf("%lld", ans);

    return 0;
}

/*
4
10 0
5 0
0 5
0 10
 */
