#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 30002

int n, k, m, q, distances[MAX];


bool used[MAX];
vector<pair<int, int>> graph[MAX];

void dijkstra(int from)
{
    priority_queue<pair<int ,int> , vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(distances, distances + n + 1, INT_MAX / 2);
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
    cin >> n >> m;
    int x, y, t;
    for(int i = 0; i < m; ++i){
        cin >> x >> y >> t;
        graph[x].push_back({y, t});
        graph[y].push_back({x, t});
    }

    cin >> k;
    vector<int> special(k);

    for (int i = 0; i < k; i++)
    {
        cin >> special[i];
    }

    vector<int> results;

    cin >> q;
    for(int i = 0; i < q; ++i){
        y = INT_MAX;
        cin >> x;
        dijkstra(x);

        for(auto i : special){
            y = min(y, distances[i]); 
        }
        
        results.push_back(y);
    }
    
    for(auto i : results){
        cout << i <<  endl;
    }

}
