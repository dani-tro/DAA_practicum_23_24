#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1'000'000;
int N,M,K,Q;

struct edge {
    int u,v;

};

int d[SIZE];
bool visited[SIZE];
vector<int> graph[SIZE];
int queries[SIZE];
int friendFlowers[SIZE];
// void dijkstra() {
//     int s = N;
//     fill(d,d+N+2,INT_MAX/2);
//     d[N] = 0;
//    priority_queue<pair<int,int>> pq;
//    pq.push({0,s});
//    while(!pq.empty()) {
//     int curr = pq.top().second;
//     pq.pop();
//     if(visited[curr]) 
//         continue;
//     visited[curr] = true;
//     for (edge e : graph[curr]){
//         if (d[e.v] > d[curr] + e.w) {
//             d[e.v] = d[curr] + e.w;
//             pq.push({-d[e.v],e.v});
//         }
//     }
//    }
// }
int counter = 0;
int topo_sort() {
    //priority_queue<pair<int,int>> pq;
    queue<int> q;
    for (size_t i = 1; i <= 20000; i++){
        for (int v : graph[i]){
            d[v]++;
        }
    }
    for (size_t i = 1; i <= 20000; i++){
       if(d[i] == 0) {
        q.push(i);
       }
    }
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if (d[curr] >0) {
            break;
        }
        for (int v : graph[curr]){
            d[v]--;
            if (d[v]==0) {
                q.push(v);
            }
        }
        counter++;
    }
return counter;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> K;
    for (size_t i = 0; i < K;i++){
        int a;
        cin >> a;
        for (size_t j = 0; j < a; j++){
            cin >> friendFlowers[j];
        }
        for (size_t j = 0; j < a - 1; j++) {
            graph[friendFlowers[j]].push_back(friendFlowers[j+1]);
        }
    }
    
    cout << (topo_sort() == 20000);


}