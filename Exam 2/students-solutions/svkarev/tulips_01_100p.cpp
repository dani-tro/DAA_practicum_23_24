#include <bits/stdc++.h>
using namespace std;

uint32_t n,m;

vector<vector<int>> mat;
vector<vector<bool>> visited;

void dfs(int r, int c, int prev)
{
    if(r < 0 || r >= n || c < 0 || c >= m)
        return;

    if(mat[r][c] != prev)
        return;

    if(visited[r][c])
        return;

    visited[r][c] = true;

    dfs(r+1, c, mat[r][c]);
    dfs(r-1, c, mat[r][c]);
    dfs(r, c+1, mat[r][c]);
    dfs(r, c-1, mat[r][c]);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    mat.resize(n,vector<int>(m, 0));
    visited.resize(n,vector<bool>(m, false));

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    uint32_t c = 0;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if(!visited[i][j])
            {
                dfs(i,j,mat[i][j]);
                c++;
            }
        }
    }
    
    cout << c<<endl;
    
    return 0;
}
