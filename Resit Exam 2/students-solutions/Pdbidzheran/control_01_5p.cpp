//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <iomanip>
using namespace std;

const int MAX = 10000000;
int N, M;

vector<vector<int>> adj;

vector<bool> visited;
vector<int> len;

vector<int> cities;

void bfs(int start)
{
    cities.push_back(0);
    int index = cities.size() - 1;
    len.assign(N, MAX);
    len[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < adj[curr].size(); ++i)
        {
            if (visited[adj[curr][i]]) continue;
            if (len[curr] + 1 < len[adj[curr][i]])
            {
                len[adj[curr][i]] = len[curr] + 1;
                q.push(adj[curr][i]);
            }
        }
        visited[curr] = true;
        ++cities[index];
    }

}

void putIntoCities()
{
    visited.assign(N, false);

    for (int i = 0; i < N; ++i)
    {
        if (visited[i])
        {
            continue;
        }
        bfs(i);
    }
}

int ans()
{
    putIntoCities();
    int answer = 0;
    int temp = 1;

    int sz = cities.size();
    for (int i = 0; i < sz - 1; ++i)
    {
        temp = cities[i];
        for (int j = i + 1; j < sz; ++j)
        {
            temp *= cities[j];
        }
        answer += temp;
    }
    return answer;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    adj.assign(N, {});

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    cout << ans() << '\n';
}

/*


*/