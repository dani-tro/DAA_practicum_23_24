#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1000001

int n;
pair<int, int> beetles[MAX];

int parent[MAX];
int depth[MAX];
long long totalCost;

struct edge {
    int x, y;
    long long w;

    edge() : x(0), y(0), w(0) {}
    edge(int x, int y, long long w) : x(x), y(y), w(w) {}

    bool operator<(const edge& other) const {
        return w < other.w;
    }
};
vector<edge> edges;

int find(int a) {
    if (parent[a] == 0) return a;
    return parent[a] = find(parent[a]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (depth[a] > depth[b]) {
        parent[b] = a;
    } else {
        parent[a] = b;
        if (depth[a] == depth[b]) depth[b]++;
    }
}

void kruskal() {
    fill(parent, parent + n + 1, 0);
    sort(edges.begin(), edges.end());
    for (int i = 0; i < n*n; i++) {
        if(find(edges[i].x) == find(edges[i].y)) continue;
        unite(edges[i].x, edges[i].y);
        totalCost += edges[i].w;
    }
}

long long distance(int x1, int x2, int y1, int y2) {
    return pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2);
}

bool possible(long long price) {
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> beetles[i].first >> beetles[i].second;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            edges.push_back(edge(i, j, distance(beetles[i].first, beetles[j].first, beetles[i].second, beetles[j].second)));
        }
    }

    kruskal();

    cout << totalCost << endl;

    return 0;
}