#include <bits/stdc++.h>
using namespace std;

const long long SIZE = 2 * 10'000;
struct edge {
    int u,v;
    long long w;
    bool operator<(const edge& other)const {
        return this->w > other.w;
    }
};
bool visited[SIZE];

pair<long long,short> beetles[SIZE];
vector<edge> graph[SIZE];
long long total = 0;
int N;
void prim() {
    long long s=0;
    priority_queue<edge> pq;
    for (edge e : graph[s]){
        pq.push(e);
    }
    visited[s] = true;
    while(!pq.empty()) {
        edge curr = pq.top();
        pq.pop();
        if (visited[curr.v])
            continue;
        visited[curr.v] = true;
        for (edge e : graph[curr.v]){
            pq.push(e);
        }
        
        total +=curr.w;
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    for (long long i = 0; i < N;i++){
        int x,y;    
        cin >> x >> y;
        beetles[i] = {x,y};
    }
    for (long long i = 0; i < N; i++){
        pair<long long,short> curr = beetles[i];
        for (long long j = i+1; j < N; j++) {
            pair<long long,short> curr1=beetles[j];
            long long cost = (curr.first - curr1.first)*(curr.first - curr1.first) +
                            (curr.second - curr1.second) * (curr.second - curr1.second);
        graph[i].push_back((edge){i,j,cost});
        graph[j].push_back((edge){j,i,cost});
        }
    }
    prim();
    cout << total;

}