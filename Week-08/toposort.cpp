# include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4+5;
vector <int> g[MAXN];
int in[MAXN];
int n, m;
int idx = 1;
int f[MAXN];
priority_queue <int> q;
int main(){
    cin >> n >> m;
    int i, j, u, v;
    for (i = 1;i <= m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        in[v]++;
    }

    for (i = 1; i <= n; i++){
        if (in[i] == 0) q.push(-i);
    }

    while (!q.empty()){
        int curr = -q.top();
        q.pop();
        f[idx] = curr; idx++;
        for (auto u : g[curr]){
            in[u] -- ;
            if (in[u] == 0) q.push(-u);
        }
    }

    if (idx != n + 1) {cout << "Sandro fails.\n"; return 0;}
    for (i = 1;i <= n; i++) cout << f[i] << " ";
    cout << endl;
}
