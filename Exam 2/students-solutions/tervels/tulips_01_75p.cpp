#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 1024;
int n, m;
vector<int> g[MAXN*MAXN];
int matr[MAXN][MAXN];
bool visited[MAXN][MAXN];

bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int i, int j)
{
    visited[i][j] = true;

    if (valid(i+1, j) && matr[i][j] == matr[i+1][j])
        dfs(i+1, j);
    if (valid(i, j+1) && matr[i][j] == matr[i][j+1])
        dfs(i, j+1);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matr[i][j];
    
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!visited[i][j])
            {
                dfs(i, j);
                ++cnt;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}