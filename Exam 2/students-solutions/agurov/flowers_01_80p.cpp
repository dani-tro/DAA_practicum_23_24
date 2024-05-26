#include <bits/stdc++.h>
using namespace std;

#define MAX 20000
int k;
int inv[MAX];
typedef pair<int, int> pii;
vector<vector<int>> graph(MAX, vector<int>());
priority_queue<int> pq;
set<int> nodes;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k;
    int q;
    for(int i=0;i<k;i++){
        cin >> q;
        vector<int> row(q);
        for(auto &x : row) {
            cin >> x;
        }
        for(int l=0; l < q - 1; l++) {
            graph[row[l]].push_back(row[l + 1]);
            inv[row[l+1]]++;
            nodes.insert(row[l]);
            nodes.insert(row[l+1]);
        }
    }
    for(auto &x : nodes){
        if(inv[x] == 0)
            pq.push(x);
    }
    
    int count = nodes.size();
    while(!pq.empty()){
        int u=pq.top();
        pq.pop();
        count--;
        for(auto &x : graph[u]){
            inv[x]--;
            if(inv[x]==0){
                pq.push(x);
            }
        }
    }
    cout << (count == 0);
}
