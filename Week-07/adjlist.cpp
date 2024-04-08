# include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
vector <int> g[1005];
int n, m;
void neighbours (int u){
    for (int i = 0; i < g[u].size(); i++){
        cout << g[u][i] << " ";
    }
    /*for (auto v : g[u]){
        cout << v << " ";
    }*/
    cout << endl;
}
int main(){
    cin >> n >> m;
    int i, j, u, v;
    for (i = 0; i < m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    neighbours(3);

}
