#include <bits/stdc++.h>

#define MAX ((unsigned long long)1e3)

using namespace std;

pair<int, bool> gr[MAX][MAX]; //color, visited
queue<pair<int, int>> Q;

int n, m;

void BFS(int x, int y) {
    Q.emplace(x, y);
    int color = gr[x][y].first;
    gr[x][y].second = true; //visited

    while (!Q.empty()) {
        auto p = Q.front();
        x = p.first;
        y = p.second;
        Q.pop();

        if (x + 1 < n)
            if (gr[x + 1][y].first == color && !gr[x + 1][y].second) {
                gr[x + 1][y].second = true;
                Q.emplace(x+1, y);
            }
        if (y + 1 < m)
            if (gr[x][y + 1].first == color && !gr[x][y + 1].second) {
                gr[x][y + 1].second = true;
                Q.emplace(x, y+1);
            }
        if (x > 0)
            if (gr[x-1][y].first == color && !gr[x-1][y].second) {
                gr[x-1][y].second = true;
                Q.emplace(x-1, y);
            }
        if (y > 0)
            if (gr[x][y-1].first == color && !gr[x][y-1].second) {
                gr[x][y-1].second = true;
                Q.emplace(x, y-1);
            }
    }
}


int main() {
    scanf("%i %i", &n, &m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int temp;
            scanf("%i", &temp);
            gr[i][j].first = temp;
            gr[i][j].second = false;
        }
    }


    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!gr[i][j].second) {
                cnt++;
                BFS(i, j);
            }
        }
    }

    printf("%i", cnt);
    /*
     * 4 3
5 3 2
5 1 1
5 5 5
1 1 2

     */

    return 0;
}


