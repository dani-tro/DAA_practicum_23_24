#include <bits/stdc++.h>

const int MAX_SIZE = 2*1e5;
int in[MAX_SIZE];
std::set<int> set;
std::vector<int> g[MAX_SIZE];
int n,m, a, b;

bool topoSort(int size) {
    std::queue<int> q;
    int count = 0;
    for(int flower : set) {
        if(!in[flower]) {
            q.push(flower);
            count++;
        }
    }
    
    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int adj : g[curr]) {
            in[adj]--;
            if(in[adj] == 0) {
                q.push(adj);
                count++;
            }
        }
    }

    return count == size;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>n;
    for (size_t i = 0; i < n; i++) {
        std::cin>>m;
        std::cin>>a;
        for (size_t i = 0; i < m - 1; i++) {
            std::cin>>b;
            set.insert(a);
            set.insert(b);
            g[a].push_back(b);
            in[b]++;
            a = b;
        }
    }
    
    std::cout<<topoSort(set.size())<<std::endl;
}