#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
const int N = 1e3+5;

vector<vector<int>> adj(N, vector<int> (N));
vector<vector<int>> visited(N, vector<int> (N));

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(pair<int, int> s, int c) {
    int x = s.first;
    int y = s.second;

    if (visited[x][y] != -1)
    {
        cout << "x= " << x << " y=" << y << '\n';
        return;
    }
    
    visited[x][y] = c;

    for (size_t i = 0; i < 4; i++)
    {
       
        if (x + 1 < n && adj[x][y] == adj[x+1][y])
        {
            dfs({x + 1, y}, c);
        }

        if (x > 0 && adj[x][y] == adj[x-1][y])
        {
            dfs({x - 1, y}, c);
        }

        if (y > 0 && adj[x][y] == adj[x][y - 1])
        {
            dfs({x, y - 1}, c);
        }

        if (y + 1 < n && adj[x][y] == adj[x][y + 1])
        {
            dfs({x, y +1 }, c);
        }
}
    
}

int main() {

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            visited[i][j] = -1;
        }
        
    }
    
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
        }
        
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == -1)
            {
                dfs({i, j}, k++);   
            }
        }
        
    }

    cout << k;
    
    
}