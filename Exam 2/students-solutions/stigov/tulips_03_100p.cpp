#include <bits/stdc++.h>
using namespace std;

int n, m;
// int A[1003][1003];

vector<int> g[1000002];
bool visited[1000002];

struct Point
{
    int x, y;
};

void bfs(int s)
{
    queue<int> pq;
    pq.push(s);
    visited[s] = true;
    while(!pq.empty())
    {
        int v = pq.front();
        pq.pop();

        for(int u: g[v])
        {
            if(!visited[u])
            {
                pq.push(u);
                visited[u] = true;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> m;

    vector<int> upper;
    vector<int> dwn;

    for (int j = 0; j < m; j++)
    {
        int tm;
        cin >> tm;
        dwn.push_back(tm);
    }

    for (int j = 0; j < m - 1; j++)
    {
        if (dwn[j] == dwn[j + 1])
        {
            g[j].push_back(j + 1);
            g[j + 1].push_back(j);
        }
    }

    for (int i = 1; i < n; i++)
    {
        upper = dwn;
        dwn.clear();
        for (int j = 0; j < m; j++)
        {
            int tm;
            cin >> tm;
            dwn.push_back(tm);
        }

        for (int j = 0; j < m - 1; j++)
        {
            if (dwn[j] == dwn[j + 1])
            {
                g[i * m + j].push_back(i * m + j + 1);
                g[i * m + j + 1].push_back(i * m + j);
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (dwn[j] == upper[j])
            {
                g[i * m + j].push_back((i - 1) * m + j);
                g[(i - 1) * m+ j].push_back(i * m + j);
            }
        }
    }
    int cnt = 0;

    // for(int i = 0; i <= n*m)

    for (int i = 0; i < n*m; i++)
    {
        if(!visited[i])
        {
            bfs(i);
            cnt++;
        }
    }

    cout << cnt;
}