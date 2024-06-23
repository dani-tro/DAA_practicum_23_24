#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000007

long long n, m, a, b, u, cnt, idx, sz[MAXN];
long long ans;
vector<long long> g[MAXN];
bool visited[MAXN];
queue<long long> q;

void bfs(long long start, long long& cnt)
{
    q.push(start);
    visited[start] = 1;
    cnt++;

    while (!q.empty())
    {
        u = q.front();
        q.pop();

        for (auto v : g[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = 1;
                cnt++;
            }
        }     
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (long long i = 0; i < m; i++)
    {
        cin >> a >> b;
        if (a > n - 1 || b > n - 1)
        {
            cout << -1;
            return 1;
        }

        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (long long i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cnt = 0;
            bfs(i, cnt);
            sz[idx++] = cnt;
            //cout << cnt << endl;
        }
    }
    
    for (long long i = 0; i < idx; i++)
    {
        ans += sz[i] * (n - sz[i]);
    }
    
    ans /= 2;
    cout << ans << endl;

    return 0;
}