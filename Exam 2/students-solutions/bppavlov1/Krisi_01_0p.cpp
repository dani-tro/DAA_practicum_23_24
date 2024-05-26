#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int ans[100000];
int n,m,k,q;
bool used[100000];
int dist[100000];

vector<pair<int, int> > gr[100000];

void dijkstra(int start) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX / 2;
    }

    priority_queue<pair<int, int> > pq;
    dist[start] = 0;
    pq.push(make_pair(dist[start], start));

    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        if (used[node]) continue;
        used[node] = true;

        for (auto v : gr[node]) {
            int u = v.first;
            int w = v.second;

            if (dist[u] > dist[node] + w) {
                dist[u] = dist[node] + w;
                pq.push(make_pair(-dist[u], u));
            }
        }

    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cin >> n >> m;

    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        gr[a].push_back(make_pair(b,c));
        gr[b].push_back(make_pair(a,c));
    }

    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> a;
        gr[n].push_back(make_pair(a, 0));
    }

    cin >> q;

    for(int i = 0; i < q; i++) {
        cin >> ans[i];
    }
    
    dijkstra(n);

    for(int i = 0; i < q; i++) {
        cout << dist[ans[i]] << endl;
    }

    return 0;
}