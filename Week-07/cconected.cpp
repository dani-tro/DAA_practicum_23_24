# include <bits/stdc++.h> // O(n + m)
# include <algorithm>
using namespace std;
const int MAXN = 1e6+5;
vector <int> g[MAXN];
bool visited [MAXN];
int n, m;
queue <int> q;
void bfs (int u){
    q.push(u);
    visited[u] = true;
    while (!q.empty()){
        u = q.front();
        q.pop();
        for (auto v : g[u]){
            if (visited[v]) continue;
            visited[v] = true;
            q.push(v);
        }
    }
}
int ccomponents (){
    int counter = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            counter ++;
            bfs (i);
        }
    }
    return counter;
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
    cout << ccomponents () << endl;

}
