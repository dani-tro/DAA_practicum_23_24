# include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
bool adj[MAXN][MAXN];
int n, m;
void neighbours (int u){
    for (int i = 1; i <= n; i++){
        if (adj[u][i]) cout << i << " ";
    }
    cout << endl;
}
int main(){
    cin >> n >> m;
    int i, j, u, v;
    for (i = 0; i < m; i++){
        cin >> u >> v;
        adj[u][v] = true;
        adj[v][u] = true; //undirected
    }
    neighbours(3);
}
