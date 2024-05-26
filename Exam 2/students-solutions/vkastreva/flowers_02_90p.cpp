#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int n, pr, nex, k, idx =1;
bool vis[20001];
int deg[20001];
int f[20001];
set <int> flowers;

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
            else deg[nex]++;
            //pr = nex;
            flowers.insert(pr);
            flowers.insert(nex);
            for(int j = 0; j < n-2; j++){
                pr = nex;
                cin >> nex;
                gr[pr].push_back(nex);

              //  if(deg[pr]==-1) deg[pr] = 0;
                if(deg[nex]==-1) deg[nex] = 1;
                else deg[nex]++;
                flowers.insert(nex);
                //deg[nex]++;
            }
        }

    }
}

bool foundCycle = false;
priority_queue <int> q;

void toposort(){
    for (int i = 1; i <= 20000; i++){
        if (deg[i] == 0) q.push(-i);
    }
    while (!q.empty()){
        int curr = -q.top();
        q.pop();
        idx++;
        for (auto u : gr[curr]){
            deg[u]--;
            if (deg[u] == 0) q.push(-u);
        }
    }

    if (idx-1 != flowers.size()) cout << "0";
    else cout << 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    toposort();

    return 0;
}
