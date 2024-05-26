#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int node;
    int weight;
};

void dijkstra(const vector<vector<Edge>>& graph, const vector<int>& importantPlaces, vector<int>& minDistances) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap
    for (int place : importantPlaces) {
        pq.push({0, place});
        minDistances[place] = 0;
    }

    while (!pq.empty()) {
        auto [currentDist, currentNode] = pq.top();
        pq.pop();

        if (currentDist > minDistances[currentNode]) continue;

        for (const auto& edge : graph[currentNode]) {
            int nextNode = edge.node;
            int weight = edge.weight;
            if (minDistances[currentNode] + weight < minDistances[nextNode]) {
                minDistances[nextNode] = minDistances[currentNode] + weight;
                pq.push({minDistances[nextNode], nextNode});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> graph(N);
    for (int i = 0; i < M; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        graph[x].push_back({y, t});
        graph[y].push_back({x, t});
    }

    int K;
    cin >> K;
    vector<int> importantPlaces(K);
    for (int i = 0; i < K; ++i) {
        cin >> importantPlaces[i];
    }

    int Q;
    cin >> Q;
    vector<int> hotels(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> hotels[i];
    }

    vector<int> minDistances(N, INT_MAX);
    dijkstra(graph, importantPlaces, minDistances);

    for (int hotel : hotels) {
        cout << minDistances[hotel] << endl;
    }

    return 0;
}