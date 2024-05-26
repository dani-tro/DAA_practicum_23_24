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
vector<pair<int, int>> places;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m;
    cin >> n;
    long long u, v, w;
    for (long long i = 0; i < n; i++){
        cin >> u >> v;
        places.push_back({u, v});

    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i!=j){
                if(abs(places[i].first-places[j].second)<10e12) {
                    w = (places[i].first - places[j].first) * (places[i].first - places[j].first)
                        + (places[i].second - places[j].second) * (places[i].second - places[j].second);
                    if (w > 0) {
                        g[i].push_back({i, j, w});
                        g[j].push_back({j, i, w});
                    }
                }
            }

        }
    }
    added[0] = 1;
    long long sum = 0;
    for (auto u : g[0]) {
        pq.push(u);
    }
    while (!pq.empty()){
        edge curr_ed = pq.top();
        pq.pop();
        if (added[curr_ed.v]) continue;
        ans.push_back(curr_ed);
        sum += curr_ed.w;
        long long to =curr_ed.v;
        added[to] = 1;
        for (auto u : g[to]) pq.push(u);
    }
        cout << sum << endl;
}