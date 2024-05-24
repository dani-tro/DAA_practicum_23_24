# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
vector <pair <int, int> > g[maxn];
vector <pair <int, int> > prom[maxn];
long long d[maxn];
bool vis[maxn];
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int i, j, c;
    for (i = 1; i <= n; i++){
        cin >> c;
        g[0].push_back({i,c});
    }

    int a, x, y;
    for (i = 1; i <= m; i++){
        cin >> a >> x >> y;
        prom[x].push_back({y,a});
        prom[y].push_back({x,a});
    }

    priority_queue <pair <int, int> > pq;
    fill (d, d+n+2, INT_MAX);
    d[0] = 0;
    pq.push({0,0});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (auto p : prom[u]){
            g[p.first].push_back({p.second, d[u]});
        }

        for (auto p : g[u]){
            if (vis[p.first]) continue;
            if (d[p.first] > d[u] + p.second){
                d[p.first] = d[u] + p.second;
                pq.push({-d[p.first],p.first});
            }
        }

    }

    cout << d[1] << endl;

}
