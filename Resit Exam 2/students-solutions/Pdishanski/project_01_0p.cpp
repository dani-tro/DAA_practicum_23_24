#include <queue>
#include <iostream>

#define MAX1 200'000
#define MAX2 100'000

struct Edge {
    unsigned int A = 0;
    unsigned int B = 0;
    unsigned int C = 0;

    bool operator<(const Edge& edge) const {
        return this->C > edge.C;
    }

    void print() {
        std::cout << "{ ";
        std::cout << A << ", ";
        std::cout << B << ", ";
        std::cout << C << " }";
    }
};

unsigned int N = 0;
unsigned int M = 0;

unsigned int X = 0;
unsigned int Y = 0;
unsigned int Z = 0;

int degrees[MAX1] = { 0 };

std::priority_queue<Edge> edges;

void printEdges() {
    while (edges.empty() == false) {
        Edge current = edges.top();
        current.print();
        edges.pop();
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> M >> N;

    for (unsigned int i = 0; i < M; ++i) {
        std::cin >> X >> Y >> Z;
        degrees[X] += 1;
        degrees[Y] -= 1;
        edges.push({ X, Y, Z });
    }

    printEdges();

    return 0;
}
