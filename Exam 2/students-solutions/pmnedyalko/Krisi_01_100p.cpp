#include <bits/stdc++.h>

struct edge {
    int second, w;
};

const int MAX_SIZE = 1e5 + 10;
std::vector<edge> g[MAX_SIZE];
std::priority_queue<std::pair<int,int>> pq;
std::vector<int> ans;
int dist[MAX_SIZE];
int n,m,k,q;
int a,b,c;

void dijkstra(int start) {
    dist[start] = 0;
    pq.push({dist[start], start});

    while(!pq.empty()) {
        int curr = pq.top().second;
        int currDist = -pq.top().first;
        pq.pop();

        if(currDist != dist[curr]) continue;

        for(edge ed : g[curr]) {
            if(dist[ed.second] > dist[curr] + ed.w) {
                dist[ed.second] = dist[curr] + ed.w;
                pq.push({-dist[ed.second], ed.second});
            }
        }
    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin>>n>>m;
    for (size_t i = 0; i < m; i++) {
        std::cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    std::cin>>k;
    for (size_t i = 0; i < k; i++) {
        std::cin>>a;
        g[a].push_back({n,0});
        g[n].push_back({a,0});
    }

    for (size_t i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    
    dijkstra(n);

    std::cin>>q;
    for (size_t i = 0; i < q; i++) {
        std::cin>>a;
        ans.push_back(dist[a]);
    }
    
    for (size_t i = 0; i < ans.size(); i++) {
        std::cout<<ans[i]<<std::endl;
    }
    
    
}