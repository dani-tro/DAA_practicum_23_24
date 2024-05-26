#include <bits/stdc++.h>

const int MAX_SIZE = 1028;
std::vector<int> g[MAX_SIZE*MAX_SIZE];
int matrix[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE*MAX_SIZE];
int n,m;

int getIndex(int x, int y) {
    return x*m + y + 1;
}

void bfs(int start) {
    visited[start] = true;
    std::queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int adj : g[curr]) {
            if(!visited[adj]) {
                q.push(adj);
                visited[adj] = true;
            }
        }
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin>>n>>m;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            std::cin>>matrix[i][j];

            int index = getIndex(i,j);
            if(i>0 && matrix[i-1][j] == matrix[i][j]) {
                g[index].push_back(index - m);
                g[index -m].push_back(index);
            }

            if(j>0 && matrix[i][j-1] == matrix[i][j]) {
                g[index].push_back(index - 1);
                g[index -1].push_back(index);
            }
        }
    }

    int count = 0;
    for (size_t i = 1; i <= n*m; i++) {
        if(!visited[i]) {
            bfs(i);
            count++;
        }
    }
    
    std::cout<<count<<std::endl;
    return 0;
}