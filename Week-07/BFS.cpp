# include <bits/stdc++.h> // O(n + m)
# include <algorithm>
using namespace std;
const int MAXN = 1005;
vector <int> g[1005];
bool visited [MAXN];
int n, m;
queue <int> q;
void bfs (int u){
    q.push(u);
    visited[u] = true;
    while (!q.empty()){
        u = q.front();
        cout << u << " ";
        q.pop();
        for (auto v : g[u]){
            if (visited[v]) continue;
            visited[v] = true;
            q.push(v);
        }
    }
    cout << endl;
}

int main(){
    cin >> n >> m; // n - number of vertices; m - number of edges
    int i, j, u, v;
    for (i = 0; i < m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (i = 0; i < n; i++){
        sort (g[i].begin(), g[i].end());
    }
    bfs (0);

}
