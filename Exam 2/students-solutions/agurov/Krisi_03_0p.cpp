#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
long long n, m, k, q;

long long d[MAX];
bool used[MAX];

typedef pair<long long, long long> pll;
priority_queue<pll> pq;

vector<vector<pll>> graph(MAX, vector<pll>());

void djiikstra(long long s) {
    for (int i = 0; i < n; i++) {
        d[i] = INT_MAX;
        used[i] = false;
    }
    d[s] = 0;
    pq.emplace(-d[s], s);
    long long u;

    while (!pq.empty()) {
        u = pq.top().second;
        pq.pop();
        if (used[u]) continue;
        used[u] = true;
        for (auto &[v, w]: graph[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.emplace(-d[v], v);
            }
        }
    }
}

void floyd() {
    cin >> n >> m;
    vector<vector<long long>> A(n, vector<long long>(n, INT_MAX));
    long long u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        A[u][v] = w;
        A[v][u] = w;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
    }
    cin >> k;
    vector<long long> important(k);
    for (auto &x: important) {
        cin >> x;
    }

    cin >> q;
    long long x;
    for (int i = 0; i < q; i++) {
        cin >> x;
        long long minP = INT_MAX;
        for (auto &y: important) {
            minP = min(A[x][y], minP);
        }
        cout << minP << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
/*
    cin >> n >> m;
    long long u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    cin >> k;
    vector<long long> important(k);
    for (auto &x: important) {
        cin >> x;
    }

    cin >> q;
    long long x;
    for (int i = 0; i < q; i++) {
        cin >> x;
        djiikstra(x);
        long long minP = INT_MAX;
        for (auto &y: important) {
            minP = min(d[y], minP);
        }
        cout << minP << endl;
    }
*/
    floyd();
}
