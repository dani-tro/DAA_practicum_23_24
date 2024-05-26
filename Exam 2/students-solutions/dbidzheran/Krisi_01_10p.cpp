//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

const int MAX = INT32_MAX;
// we need Floyd but I don't get it so we will try with Dijkstra

struct node
{
    int a, b;

    bool operator<(const node& other) const
    {
        return b < other.b;
    }
};
int n, m, k, q;
vector<vector<node>> city;
vector<int> places;
vector<int> hotels;

vector<int> dijkstra(int start)
{
    vector<int> res;
    vector<bool> visited;
    for (int i = 0; i < n; ++i)
    {
        res.push_back(MAX);
        visited.push_back(false);
    }
    priority_queue<node> pq;
    pq.push({ start, 0 });
    res[start] = 0;

    while (!pq.empty())
    {
        node curr = pq.top();
        pq.pop();
        if (visited[curr.a]) continue;
        visited[curr.a] = true;

        for (int i = 0; i < city[curr.a].size(); ++i)
        {
            pq.push({ city[curr.a][i]});

            if (res[city[curr.a][i].a] > res[curr.a] + city[curr.a][i].b)
            {
                res[city[curr.a][i].a] = res[curr.a] + city[curr.a][i].b;
            }
        }
    }
    return res;
}
void solve()
{
    vector<int> ansArr;
    vector<int> ans;
    for (int i = 0; i < q; ++i)
    {
        ansArr = dijkstra(hotels[i]);
        ans.push_back(ansArr[places[0]]);
        for (int j = 1; j < k; ++j)
        {
            if (ans[i] > ansArr[places[j]])
            {
                ans[i] = ansArr[places[j]];
            }
        }
        ansArr.clear();
        cout << ans[i] << '\n';
    }

}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        city.push_back({});
    }

    for (int j = 0; j < m; ++j)
    {
        int a, b, c;
        cin >> a >> b >> c;
        city[a].push_back({ b, c });
        city[b].push_back({ a, c });
    }

    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int a;
        cin >> a;
        places.push_back(a);
    }
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int a;
        cin >> a;
        hotels.push_back(a);
    }
    solve();

}
