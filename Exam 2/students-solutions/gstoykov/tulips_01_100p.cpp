#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1005;
bool visited[SIZE][SIZE];
int m[SIZE][SIZE];
int N,M;
int counter = 0;
void bfs(pair<int,int> p) {
    queue<pair<int,int>> q;
    q.push(p);
    while(!q.empty()) {
        pair<int,int> curr = q.front();
        q.pop();
        int y = curr.first;
        int x = curr.second;
        if (visited[y][x]) {
            continue;
        }
        visited[y][x] = true;
        if (x - 1 >=0 && !visited[y][x-1] && m[y][x] == m[y][x-1])
            q.push({y,x-1});
        if (x + 1 < M && !visited[y][x+1]&& m[y][x] == m[y][x+1])
            q.push({y,x+1});
        if (y - 1 >=0 && !visited[y-1][x]&& m[y][x] == m[y-1][x])
            q.push({y-1,x});
        if (y + 1 <N && !visited[y+1][x]&& m[y][x] == m[y + 1][x])
            q.push({y+1,x});
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M; 
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++){
            cin >> m[i][j];
        }    
    }
     for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++){
            if (!visited[i][j]) {
                counter++;
                bfs({i,j});
            }
        }    
    }
    cout << counter;
}