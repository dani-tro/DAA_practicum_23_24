#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAXN = 1024;
int n, m;
vector<int> g[MAXN*MAXN];
int matr[MAXN][MAXN];
bool visited[MAXN*MAXN];

int id(int x, int y)
{
    return x*m + y;
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for (auto v : g[u])
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
    }
}
int ccomponents()
{
    int cnt = 0;
    for (int i = 0; i < n * m; ++i)
        if (!visited[i])
        {
            ++cnt;
            bfs(i);
        }

    return cnt;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matr[i][j];
    
    int cnt = 0;
    for (int i = 1; i < m; ++i)
        if (matr[0][i] == matr[0][i-1])
        {
            g[id(0,i)].push_back(id(0, i-1));
            g[id(0,i-1)].push_back(id(0,i));
        }
    for (int j = 1; j < n; ++j)
    {
        if (matr[j][0] == matr[j-1][0])
        {
            g[id(j,0)].push_back(id(j-1, 0));
            g[id(j-1,0)].push_back(id(j,0));
        }
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (matr[i][j] == matr[i-1][j])
            {
                g[id(i,j)].push_back(id(i-1,j));
                g[id(i-1,j)].push_back(id(i,j));
            }
            if (matr[i][j] == matr[i][j-1])
            {
                g[id(i,j)].push_back(id(i,j-1));
                g[id(i,j-1)].push_back(id(i,j));
            }
        }
    }

    cout << ccomponents() << endl;
    return 0;
}