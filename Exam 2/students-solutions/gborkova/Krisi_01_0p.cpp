#include <bits/stdc++.h>
#define MAX_VERTICES ((unsigned long long)1e5+2)

using namespace std;

int n, m, k, q, hotel;
int x, y, t;

int places[MAX_VERTICES];

vector<pair<int, int>> gr[MAX_VERTICES]; //maybe unused

int dist[MAX_VERTICES + 1][MAX_VERTICES + 1]; // dist[source][destination]

int main() {
    scanf("%i %i", &n, &m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = INT_MAX / 2;
        }
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        scanf("%i %i %i", &x, &y, &t);
        dist[x][y] = std::min(std::min(dist[x][y], dist[y][x]), t);
    }

    scanf("%i", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%i", &places[i]);
    }

    for (int through = 0; through < n; ++through) {
        for (int from = 0; from < n; ++from) {
            for (int to = 0; to < n; ++to) {
                if (dist[from][through] + dist[through][to] < dist[from][to]) {
                    dist[from][to] = dist[from][through] + dist[through][to];
                }
            }
        }
    }

    scanf("%i", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%i", &hotel);

        int opt = INT_MAX / 2;

        for (int j = 0; j < k; ++j) {
            if (dist[hotel][places[j]] < opt)
                opt = dist[hotel][places[j]];
            if (dist[places[j]][hotel] < opt)
                opt = dist[places[j]][hotel];
        }

        printf("\n%i", opt);
    }

    return 0;
}