#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxn = 1e6;
vector<int> arr[maxn];
bool visited[maxn];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    
    queue<int> q;
    long long res = n * (n-1) / 2;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            assert(q.empty());
            q.push(i);
            visited[i] = true;
            long long sz = 0;
            while(!q.empty()) {
                sz++;
                int f = q.front(); q.pop();
                for(int child : arr[f]) {
                    if (!visited[child]) {
                        q.push(child);
                        visited[child] = true;
                    }
                }
            }
            res -= sz * (sz - 1) / 2;
        }
}
    }
    cout << res << endl;
}
