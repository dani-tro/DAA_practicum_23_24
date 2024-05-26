#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
#define MAXN  10004
#define MAXM 30005

int n, k, m, q;

bool used[MAXN];
vector<pair<int, int>> graph[MAXM];

void dijkstra(int from, vector<int>& distances)
{
    priority_queue<pair<int ,int>> pq;
    fill(distances.begin(), distances.end(), INT_MAX);
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
        graph[x].push_back(make_pair(y, t));
        graph[y].push_back(make_pair(x, t));
    }

    vector<int> distances(n);

    cin >> k;
    vector<int> special;

    for (int i = 0; i < k; i++)
    {
        cin >> x;
    }

    vector<int> results;

    cin >> q;
    for(int i = 0; i < q; ++i){
        y = INT_MAX;
        cin >> x;
        dijkstra(x, distances);

        for(auto i : special){
            y = min(y, distances[i]); 
        }
        
        results.push_back(y);
    }
    
    for(auto i : results){
        cout << i <<  endl;
    }
}
