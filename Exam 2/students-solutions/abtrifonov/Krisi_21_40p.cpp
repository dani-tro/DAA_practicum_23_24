#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
#define MAXN 10010
#define MAXM 30010

int n, k, m, q;

long long distances[MAXN];

bool used[MAXN];
vector<pair<int, int>> graph[MAXN];

void dijkstra(int from)
{
    priority_queue<pair<int, int>> pq;
    fill(distances, distances + n + 5, INT_MAX/5);
    distances[from] = 0;
    pq.push({distances[from], from});

    while (!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        if (!used[node])
        {
            used[node] = true;
            for (auto p : graph[node])
            {
                int u = p.first;
                int v = p.second;
                if (distances[u] > distances[node] + v)
                {
                    distances[u] = distances[node] + v;
                    pq.push({-distances[u], u});
                }
            }
        }
    }

    fill(used, used + n + 5, false);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    cin >> n >> m;
    int x, y, t;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> t;
        graph[x].push_back(make_pair(y, t));
        graph[y].push_back(make_pair(x, t));
    }

    cin >> k;
    vector<vector<int>> special;

    for (int i = 0; i < k; i++)
    {
        cin >> x;
        dijkstra(x);
        vector<int> a{};
        special.push_back(a);
        for (int j = 0; j < n; j++)
        {
            special[i].push_back(distances[j]);
        }
    }

    vector<int> results;

    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        y = INT_MAX;
        cin >> x;

        for(int j = 0; j < k; ++j){
            y = min(y, special[j][x]);
        }

        results.push_back(y);
    }

    for (auto i : results)
    {
        cout << i << endl;
    }
}