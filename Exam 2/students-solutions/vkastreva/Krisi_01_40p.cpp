#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int n, m, s, k, q;
bool vis[10000];
int paths[10000];
int prevPath[10000];
vector<pair<int, int>> gr[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;



void input(){
    fill(prevPath, prevPath+10000, INT_MAX);

    cin >> n >> m;
    int f, t, w;
    for(int i = 0; i < m; i++){
        cin >> f >> t >> w;
        gr[f].push_back({w, t});
        gr[t].push_back({w, f});
    }
}

void dijkstra(int curr){
    //auto p = pq.top();
    fill(paths, paths+10000, INT_MAX);
    fill(vis, vis+10000, false);
    paths[curr] = 0;
    pq.push({0, curr});
    while(!pq.empty()){
        curr = pq.top().second;
        pq.pop();

        if(vis[curr]) continue;
        vis[curr] = true;

        for (auto e : gr[curr]) {
            int weight = e.first;
            int next = e.second;
            if (paths[curr] + weight < paths[next]) {
                paths[next] = paths[curr] + weight;
                pq.push({paths[next], next});
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    cin >> k;
    int curr;

    for(int i = 0; i < k; i++){
        cin >> curr;
        dijkstra(curr);
        for(int i = 0; i < n; i++){
            if(prevPath[i] > paths[i]){
                prevPath[i] = paths[i];
            }
        }
    }

    //dijkstra(s);
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> curr;
        cout << prevPath[curr] << '\n';
    }

    return 0;
}
