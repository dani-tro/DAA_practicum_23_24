#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 100100

void fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

struct edge
{
    int v;
    int t;

    bool operator<(const edge& other) const
    {
        return t > other.t;
    }
};

int n, m, x, y, t, k, q;
vector<edge> gr[MAXN];

long long d[MAXN];
bool visited[MAXN];
priority_queue<pair<long long, int>> pq;

void dijkstra(int start) 
{
    d[start] = 0;
    pq.push({ d[start], start });

    while(!pq.empty()) {
        auto u = pq.top();
        pq.pop();

        if(visited[u.second]) continue;
        visited[u.second] = true;

        for(edge e : gr[u.second]) {
            if(d[e.v] > d[u.second] + e.t) {
                d[e.v] = d[u.second] + e.t;
                pq.push({ -d[e.v], e.v });
            }
        }
    }
}

int main()
{
    fast_IO();

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> x >> y >> t;

        gr[x].push_back({ y, t });
        gr[y].push_back({ x, t });
    }

    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> x;

        gr[n].push_back({ x, 0 });
    }

    fill(d, d + n + 2, INT_MAX);
    dijkstra(n);

    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> x;

        cout << d[x] << "\n";
    }


    // for(int i = 0; i <= n; i++) {
    //     cout << d[i] << " ";
    // }
    // cout << endl;

    return 0;
}