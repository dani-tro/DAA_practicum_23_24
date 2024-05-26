#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int n, pr, nex, k;
bool vis[20001];
int deg[20001];

vector<int> gr[20001];

void input(){
    fill(deg, deg+20001, -1);
    fill(vis, vis+20001, 0);
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> n;
        if(n > 1){
            cin >> pr >> nex;
            gr[pr].push_back(nex);
            if(deg[pr]==-1) deg[pr] = 0;
            if(deg[nex]==-1) deg[nex] = 1;
            pr = nex;
            for(int j = 0; j < n-2; j++){
                cin >> nex;
                gr[pr].push_back(nex);
                pr = nex;
                if(deg[pr]==-1) deg[pr] = 0;
                if(deg[nex]==-1) deg[nex] = 1;
                deg[nex]++;
            }
        }

    }
}

bool foundCycle = false;

void dfs(int u){
    fill(vis, vis+n, 0);
    vis[u]= true;
    for (auto v : gr[u]){
        if(!vis[v]){
            dfs(v);
            vis[v] = false;
        } else {
            foundCycle = true;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    int index=0;
    bool zeroDeg=false;
    for(int i = 0; i < n; i++){
        if(deg[i]==0) {
            dfs(i);
            if(foundCycle) {
                cout << "0";
                break;
            }
            zeroDeg = true;

        }
    }
    if(!zeroDeg) {
        cout << "0";
        return 0;
    }
    if(!foundCycle) cout << "1";
    else cout << "0";

    return 0;
}
