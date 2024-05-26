#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
typedef pair<int, int> pii;

int n, m;


int findUnvisited(const vector<bool> &visited) {
    for (int i = 0; i < m * n; i++) {
        if (!visited[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for (auto &row: matrix) {
        for (auto &x: row) {
            cin >> x;
        }
    }

    vector<vector<int>> graph(n * m, vector<int>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i >= 1) {
                if (matrix[i - 1][j] == matrix[i][j]) {
                    graph[i * m + j].push_back((i - 1) * m + j);
                    graph[(i - 1) * m + j].push_back(i * m + j);
                }
            }
            if (j >= 1) {
                if (matrix[i][j - 1] == matrix[i][j]) {
                    graph[i * m + j].push_back(i * m + (j - 1));
                    graph[i * m + (j - 1)].push_back(i * m + j);
                }
            }
        }
    }
    vector<bool> visited(n * m, false);
    int count = 0;
    queue<int> q;
    int next;
    while ((next = findUnvisited(visited)) != -1) {
        count++;
        q.push(next);
        visited[next] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &v: graph[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    cout << count;

}
