# include <bits/stdc++.h> // O(n*m + n*m + 4*n*m) = O(n*m)
using namespace std;
int n, m;
bool matrix[105][105];
const int MAXV = 1e4+5;
bool visited[MAXV];
vector <int> g[MAXV];
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
    for (int i = 1; i <= n*m; i++){
        if (!visited[i]){
            counter ++;
            bfs (i);
        }
    }
    return counter;
}

int id (int x, int y){
    return (x-1)*m+y;
}
int main(){
    cin >> n >> m;
    int i, j;
    int k, x, y;
    cin >> k;
    for (i = 0; i < k; i++){
        cin >> x >> y;
        matrix[x][y] = 1;
        visited[id(x,y)] = 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (matrix[i][j]) continue;
            if (i > 1 && matrix[i-1][j] == 0){
                g[id(i,j)].push_back(id(i-1,j));
                g[id(i-1,j)].push_back(id(i,j));
            }
            if (j > 1 && matrix[i][j-1] == 0){
                g[id(i,j)].push_back(id(i,j-1));
                g[id(i,j-1)].push_back(id(i,j));
            }
        }
    }
    int ans = ccomponents();
    cout << ans << endl;

}
