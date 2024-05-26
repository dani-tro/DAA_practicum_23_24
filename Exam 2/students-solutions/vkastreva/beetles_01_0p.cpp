#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int n, m;
bool vis[100001];
bool added[100001];

struct coord{
    int x, y;

    bool operator<(coord &other){
        return x < other.x || (x == other.x && y < other.y);
    }
};
vector<coord> gr;
struct edge {
    long long u, v, w;
    bool operator <(const edge& other)const {
        return w > other.w;
    }
};
vector<edge> graph;
priority_queue <edge> pq;
vector <edge> g[1000005];


void buildGraph(){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            g[i].push_back({i, j, (gr[i].x-gr[j].x)*(gr[i].x-gr[j].x)+(gr[i].y-gr[j].y)*(gr[i].y-gr[j].y)});
            g[j].push_back({j, i, (gr[i].x-gr[j].x)*(gr[i].x-gr[j].x)+(gr[i].y-gr[j].y)*(gr[i].y-gr[j].y)});
        }
    }
}




void input(){
    cin >> n;
    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        gr.push_back({x, y});
    }
    sort(gr.begin(), gr.end());
    buildGraph();

    added[0] = 1;
    unsigned long long sum = 0;
    for (auto u : g[0]) {
        pq.push(u);
    }
    while (!pq.empty()){
        edge curr_ed = pq.top();
        pq.pop();
        if (added[curr_ed.v]) continue;
        //cout << "Added edge: " << curr_ed.u << " " << curr_ed.v << endl;
        sum += curr_ed.w;
        long long to =curr_ed.v;
        added[to] = 1;
        for (auto u : g[to]) pq.push(u);
    }
    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    return 0;
}
