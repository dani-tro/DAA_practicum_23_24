#include <bits/stdc++.h>

#define N 10004


std::vector<std::pair<int, int>> adj[N];
std::priority_queue<std::pair<int, int>> pq;

int n, m;
int x, y, t;
int k, p;
int q, h;

std::vector<int> places;
std::vector<int> hotels;
int distance[N];


void calcDistance(int start, std::vector<int>& targets) {
    bool visited[N];
    std::fill(distance, distance + n + 1, INT_MAX);
    distance[start] = 0;
    pq.push({distance[start], start});

    while (!pq.empty()) {
        int node = -(pq.top().first);
        pq.pop();

        for (auto pair : adj[node]) {
            if (distance[node] + pair.first < distance[pair.second]) {
                distance[pair.second] = distance[node] + pair.first;
                pq.push({-distance[pair.second], pair.second});
            }
        }
    }
}



int main() {

    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        std::cin >> x >> y >> t;
        adj[x].push_back({y, t});
        adj[y].push_back({x, t});
    }

    std::cin >> k;
    for (int i = 0; i < k; i++) {
        std::cin >> p;
        places.push_back(p);

    }

    std::cin >> q;
    for (int i = 0; i < k; i++) {
        std::cin >> h;
        hotels.push_back(h);
    }

    if (k > q) {
        std::vector<int> result(k, INT_MAX);
        std::vector<int> temp;
        for (int i = 0; i < q; i++) {
            calcDistance(places[i], hotels);
            for (int i = 0; i < result.size(); i++) {
                result[i] = std::min(result[i], distance[i]);
            }
        }
        int res = 0;
        for (auto elem : result) {
            res += elem;
        }
        std::cout << res;
    }
    else {
        std::vector<int> result(q, INT_MAX);
        std::vector<int> temp;
        for (int i = 0; i < k; i++) {
        calcDistance(hotels[i], places);
            for (int i = 0; i < result.size(); i++) {
                result[i] = std::min(result[i], distance[i]);
        }
        }
        int res = 0;
        for (auto elem : result) {
            res += elem;
        }
        std::cout << res;
    }


    return 0;
}