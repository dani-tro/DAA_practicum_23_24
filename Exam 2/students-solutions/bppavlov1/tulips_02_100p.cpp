#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long

int n, m;
int mt[1001][1001];
bool visited[1000001];

vector<int> gr[1000001];

int id(int i, int j) {
    return i*m + j;
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto v : gr[node]) {
            if (visited[v]) continue;
            q.push(v);
            visited[v] = true;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mt[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (i > 0 && mt[i][j] == mt[i-1][j]) {
                gr[id(i,j)].push_back(id(i-1,j));
            }
            if (j > 0 && mt[i][j] == mt[i][j-1]) {
                gr[id(i,j)].push_back(id(i,j-1));
            }
            if (i < n - 1 && mt[i][j] == mt[i+1][j]) {
                gr[id(i,j)].push_back(id(i+1,j));
            }
            if (j < m - 1 && mt[i][j] == mt[i][j+1]) {
                gr[id(i,j)].push_back(id(i,j+1));
            }
        }
    }



    int count = 0;
    for(int i = 0; i < n*m; i++) {
        if (visited[i]) continue;
        count++;
        bfs(i);
    }

    cout << count << endl;

    return 0;
}