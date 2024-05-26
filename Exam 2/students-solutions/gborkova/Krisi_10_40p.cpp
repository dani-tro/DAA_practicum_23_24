#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>
#define MAX ((unsigned long long)1e5)

using namespace std;

int n, m, k, q, hotel;
int x, y, t;

vector<pair<int, int>> gr[MAX];
int places[MAX];

bool used[MAX+2];
int d[MAX];
priority_queue<pair<int, int>> pq;

void dijkstra(int from) {
    fill(used, used+MAX, false);
    fill(d, d + n + 1, INT_MAX / 2);
    d[from] = 0;
    pq.emplace(d[from], from);
    int node, u, w;

    while (!pq.empty()) {
        node = pq.top().second;
        pq.pop();
        if (used[node]) continue;
        used[node] = true;

        for (auto p: gr[node]) {
            u = p.first;
            w = p.second;

            if (d[u] > d[node] + w) {
                d[u] = d[node] + w;
                pq.push({-d[u], u});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &x, &y, &t);
        gr[x].emplace_back(y, t);
        gr[y].emplace_back(x, t);
    }

    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &places[i]);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d", &hotel);

        int opt = INT_MAX / 2;

        dijkstra(hotel);

        for (int j = 0; j < k; ++j) {
            if (d[places[j]] < opt)
                opt = d[places[j]];
        }

        printf("\n%d", opt);
    }

    return 0;
}

/*
8 12
0 1 15
5 1 4
6 5 5
4 6 7
7 4 8
3 5 10
2 0 2
5 1 9
5 4 5
4 1 8
6 2 10
2 6 7
2
4 6
3
3
0
2

 */

