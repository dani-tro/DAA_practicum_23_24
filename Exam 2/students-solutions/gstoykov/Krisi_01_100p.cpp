#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1'000'000;
int N,M,K,Q;

struct edge {
    int u,v,w;
    bool operator<(const edge& other) {
        return this->w > other.w;
    }
};

int d[SIZE];
bool visited[SIZE];
vector<edge> graph[SIZE];
int queries[SIZE];
void dijkstra() {
    int s = N;
    fill(d,d+N+2,INT_MAX/2);
    d[N] = 0;
   priority_queue<pair<int,int>> pq;
   pq.push({0,s});
   while(!pq.empty()) {
    int curr = pq.top().second;
    pq.pop();
    if(visited[curr]) 
        continue;
    visited[curr] = true;
    for (edge e : graph[curr]){
        if (d[e.v] > d[curr] + e.w) {
            d[e.v] = d[curr] + e.w;
            pq.push({-d[e.v],e.v});
        }
    }
   }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        int a,b,c;
        cin >> a >> b>>c;
        graph[a].push_back({a,b,c});
        graph[b].push_back({b,a,c});
    }
    cin >> K;
    for (int i=0;i<K;i++){
        int a;
        cin >> a;
        graph[N].push_back({N,a,0});
        graph[a].push_back({a,N,0});
    }
    
    cin >> Q;
    for (size_t i = 0; i < Q; i++) {
        cin >> queries[i];
    }
    dijkstra();
    for (size_t i = 0; i < Q; i++) {
        cout << d[queries[i]] << endl;
    }
}