#include <queue>
#include <vector>

#include <cmath>

#include <iostream>

int N = 0;

long long P = 0;
long long Q = 0;
long long D = 0;

struct Pair {
    int I = -1;
    long long X = 0;
    long long Y = 0;

    void print() {
        std::cout << "{ " << this->X << ' ' << this->Y << " }";
    }
};

struct Edge {
    Pair A = { 0, 0 };
    Pair B = { 0, 0 };

    long long C = 0;

    bool operator<(const Edge& instance) const {
        return this->C > instance.C;
    }
};

bool visited[100'001];

std::vector<Pair> input;

std::priority_queue<Edge> edges;
std::priority_queue<Edge> buffer;

long long distance(Pair pair1, Pair pair2) {
    return  std::abs(pair1.X - pair2.X) * std::abs(pair1.X - pair2.X) +
            std::abs(pair1.Y - pair2.Y) * std::abs(pair1.Y - pair2.Y);
}

void printQueue() {
    while (edges.empty() == false) {
        Edge e = edges.top();
        edges.pop();

        e.A.print();
        e.B.print();
        std::cout << ' ';
        std::cout << e.C << std::endl;
    }
}

long long findCost() {
    long long result = 0;
    long long marked = N;
    int treeE = 0;

    while (edges.empty() == false) {
        if (treeE == N - 1) {
            break;
        }

        if (marked == 0) {
            break;
        }

        Edge current = edges.top();
        edges.pop();

        // current.A.print();
        // current.B.print();

        // std::cout << std::endl;

        int index1 = current.A.I;
        int index2 = current.B.I;

        // std::cout << "Indices are: " << index1 << ' ' << index2 << std::endl;

        if (visited[index1]) {
            // buffer.push(current);
            continue;
        }

        visited[index1] = true;
        // visited[index2] = true;

        result += current.C;

        treeE += 1;
        marked -= 1;

        // std::cout << "Current is: " << current.C << ' ' << result << std::endl;
    }

    // std::cout << "Marked are: " << treeE << std::endl;

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        std::cin >> P >> Q;
        Pair current = { i, P, Q };
        visited[i] = false;
        input.push_back(current);

        for (int j = 0; j < input.size() - 1; ++j) {
            D = distance(current, input[j]);
            edges.push({ current, input[j], D });
        }
    }

    std::cout << findCost() << std::endl;

    // printQueue();

    return 0;
}