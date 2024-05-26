#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>>& garden, vector<vector<bool>>& visited, int x, int y, int color) {
    int n = garden.size();
    int m = garden[0].size();
   
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    stack<pair<int, int>> s;
    s.push({x, y});
    visited[x][y] = true;
    
    while (!s.empty()) {
        int cx = s.top().first;
        int cy = s.top().second;
        s.pop();
        
        for (auto& dir : directions) {
            int nx = cx + dir[0];
            int ny = cy + dir[1];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && garden[nx][ny] == color) {
                visited[nx][ny] = true;
                s.push({nx, ny});
            }
        }
    }
}

int countBugs(vector<vector<int>>& garden, int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int bugCount = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j]) {
                dfs(garden, visited, i, j, garden[i][j]);
                bugCount++;
            }
        }
    }
    
    return bugCount;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> garden(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> garden[i][j];
        }
    }
    
    cout << countBugs(garden, N, M) << endl;
    
    return 0;
}