#include <queue>

#include <climits>

#include <iostream>

#define MAX 20'003

struct Edge {
    unsigned int A = 0;
    unsigned int B = 0;
    unsigned int C = 0;

    bool operator<(const Edge& edge) const {
        return this->C > edge.C;
    }
};

unsigned int N = 0;
unsigned int M = 0;
unsigned int K = 0;

unsigned int X = 0;
unsigned int Y = 0;
unsigned int P = 0;
unsigned int T = 0;

std::priority_queue<Edge> edges;

long long distances[MAX];

std::vector<Edge> list[MAX];

void print() {
    std::cout << "Distances are: ";

    for (unsigned int i = 0; i < N; ++i) {
        std::cout << distances[i] << ' ';
    }

    std::cout << std::endl;
}

void shortestPath(unsigned int vertex) {
    distances[vertex] = 0;

    for (auto e : list[vertex]) {
        unsigned int u = e.B;
        unsigned int w = e.C;

        if (distances[u] > distances[u] + w) {
            distances[u] = distances[u] + w;
        }

        edges.push(e);
    }

    while (edges.empty() == false) {
        unsigned int current1 = edges.top().A;
        unsigned int current2 = edges.top().B;
        unsigned int weight = edges.top().C;
    
        edges.pop();

        if (distances[current1] > distances[current2] + weight) {
            distances[current1] = distances[current2] + weight;
        }

        print();
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N >> M >> K;

    for (std::size_t i = 0; i < M; ++i) {
        std::cin >> X >> Y >> P >> T;
        edges.push({ X, Y, T - P });
        edges.push({ Y, X, T - P });

        list[X].push_back({ X, Y, T - P });
        list[Y].push_back({ Y, X, T - P });
    }

    for (std::size_t i = 0; i < N; ++i) {
        distances[i] = UINT_MAX / 2;
    }

    shortestPath(1);

    std::cout << distances[N] << std::endl;

    return 0;
}