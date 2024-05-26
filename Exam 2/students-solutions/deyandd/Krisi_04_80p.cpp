#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
using edge = pair<long, long>;

vector<vector<edge>> graph;
long dists[100000];
bool visited[100000];

void dijkstra(long src) {
    long l = graph.size();
    for (long i = 0; i < l; i++)
    {
        dists[i] = LONG_MAX;
    }

    priority_queue<edge, vector<edge>, greater<edge>> pq;

    dists[src] = 0;
    pq.push(edge(0, src));

    while (!pq.empty())
    {
        long v = pq.top().second;
        pq.pop();

        if (visited[v])
        {
            continue;
        }
        visited[v] = true;

        for (auto& e : graph[v])
        {
            if (dists[e.second] > dists[v] + e.first)
            {
                dists[e.second] = dists[v] + e.first;
                pq.push(edge(dists[e.second], e.second));
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    long n, m; cin >> n >> m;
    graph = vector<vector<edge>>(n+1);

    for (long i = 0; i < m; i++)
    {
        long from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back(edge(weight,to ));
        graph[to].push_back(edge( weight,from));
    }

    long k; cin >> k;
    for (long i = 0; i < k; i++)
    {
        long t; cin >> t;
        graph[n].push_back(edge(0, t));
        graph[t].push_back(edge(0, n));
    }

    dijkstra(n);

    long q; cin >> q;
    for (long i = 0; i < q; i++)
    {
        long t; cin >> t;
        cout << dists[t] << endl;
    }
}