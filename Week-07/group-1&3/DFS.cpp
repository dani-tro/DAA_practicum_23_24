# include <bits/stdc++.h>
# include <algorithm>
using namespace std;
const int MAXN = 1005;
vector <int> g[1005];
bool visited [MAXN];
int n, m;
void dfs (int u){ //O(n + m)
    visited [u] = true;
    cout << u << " ";
    for (auto v : g[u]){
        if (!visited[v]) dfs(v);
    }
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
    dfs (0);

}
