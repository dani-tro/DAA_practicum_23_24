# include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000005;
struct edge {
    long long u, v, w;
    bool operator <(const edge& other)const {
        return w > other.w;
    }
};
vector <edge> g[MAXN];
bool added[MAXN];
priority_queue <edge> pq;
vector <edge> ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m;
    cin >> n >> m;
    long long u, v, w;
    for (long long i = 0; i < m; i++){
        cin >> u >> v >> w;
        g[u].push_back({u,v,w});
        g[v].push_back({v,u,w});
    }

    added[1] = 1;
    long long sum = 0;
    for (auto u : g[1]) {
            pq.push(u);
            //cout << "pushed " << u.u << " " << u.v << endl;
    }
    while (!pq.empty()){
        edge curr_ed = pq.top();
        //cout << curr_ed.u << " " << curr_ed.v << endl;
        pq.pop();
        if (added[curr_ed.v]) continue;
        ans.push_back(curr_ed);
        //cout << "Added edge: " << curr_ed.u << " " << curr_ed.v << endl;
        sum += curr_ed.w;
        long long to =curr_ed.v;
        added[to] = 1;
        for (auto u : g[to]) pq.push(u);
    }
    if (ans.size() == n-1)
        cout << sum << endl;
    else
        cout << "IMPOSSIBLE\n";
}
