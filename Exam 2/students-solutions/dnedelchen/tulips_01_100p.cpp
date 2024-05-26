#include <bits/stdc++.h>
#define MAXN 1024
#define MAXV 1000003
#define endl '\n'
using namespace std;
int n, m;
int clr[MAXN][MAXN];
bool used[MAXV];
vector<int> adj[MAXV];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> clr[i][j];
}

void dfs(int tmp)
{
    used[tmp] = 1;
    int sz = adj[tmp].size();

    for (int i = 0; i < sz; ++i)
        if (!used[adj[tmp][i]])
            dfs(adj[tmp][i]);
}

void solve()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (i > 1 && clr[i][j] == clr[i - 1][j])
                adj[i * m + j].push_back((i - 1) * m + j);
            if (i < n - 1 && clr[i][j] == clr[i + 1][j])
                adj[i * m + j].push_back((i + 1) * m + j);
            if (j > 1 && clr[i][j] == clr[i][j - 1])
                adj[i * m + j].push_back(i * m + j - 1);
            if (j < m - 1 && clr[i][j] == clr[i][j + 1])
                adj[i * m + j].push_back(i * m + j + 1);
        }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!used[i * m + j])
            {
                ++cnt;
                dfs(i * m + j);
            }

    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();

    return 0;
}

/**

4 3
5 3 2
5 1 1
5 5 5
1 1 2

2 2
1 10
10 1

*/
