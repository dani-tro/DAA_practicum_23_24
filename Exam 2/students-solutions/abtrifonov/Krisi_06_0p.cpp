#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
#define MAXN  10002
#define MAXM 30005

int n, k, m, q;

vector<int> distances(MAXN);

bool used[MAXN];
vector<pair<int, int>> graph[MAXM];

void dijkstra(int from)
{
    priority_queue<pair<int ,int> , vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(distances.begin(), distances.end(), INT_MAX/3);
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
    fill(used, used + n + 2, false);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int x, y, t;
    for(int i = 0; i < m; ++i){
        cin >> x >> y >> t;
        graph[x].push_back({y, t});
        graph[y].push_back({x, t});
    }

    cin >> k;
    vector<vector<int>> special;

    for (int i = 0; i < k; i++)
    {
        cin >> x;
        dijkstra(x);
        special.push_back(distances);
    }

    vector<int> results;

    cin >> q;
    for(int i = 0; i < q; ++i){
        y = INT_MAX;
        cin >> x;
        dijkstra(x);

        for(int i = 0; i < k; ++i){
            y = min(y, special[i][x]);
        }
        
        results.push_back(y);
    }
    
    for(auto i : results){
        cout << i <<  endl;
    }

}
