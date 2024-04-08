# include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int colour[105]; // 1 | 2
    bool flag = true;
    void dfs(int u, vector <vector<int> > &g){
        for (auto v : g[u]){
            if (colour[v] == 0){
                colour[v] = 3 - colour[u];
                dfs (v, g);
            } else if (colour[u] == colour[v]){
                flag = false;
                return ;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        for (int i = 0; flag && i < n; i++){
            if (colour[i] == 0){
                colour[i] = 1;
                dfs (i, graph);
            }
        }

        return flag;
    }
};
