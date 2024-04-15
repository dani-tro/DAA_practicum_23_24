# include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4+5;
vector <int> g[MAXN];
int in[MAXN];
vector <int> ans;
int n, m;
int main(){

    cin >> n >> m;
    int i, j, u, v;
    for (i = 1; i <= m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        in[v]++;
    }

    priority_queue <int> pq;
    for (i = 1; i <= n; i++){
        if (in[i] == 0) pq.push(-i);
    }

    while (!pq.empty()){
        int curr = -pq.top();
        pq.pop();
        ans.push_back(curr);
        for (auto u : g[curr]){
            in[u] --;
            if (in[u] == 0) pq.push(-u);
        }
    }

    if (ans.size() == n) {
        for (auto v : ans) cout << v << " ";
        cout << endl;
    }
    else {
        cout << "Sandro fails.\n";
    }

}
