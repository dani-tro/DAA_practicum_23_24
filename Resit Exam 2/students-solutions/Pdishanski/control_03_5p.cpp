#include <vector>
#include <queue>

#include <iostream>

#define MAX 1'000'000

unsigned int N = 0;
unsigned int M = 0;

unsigned int L1 = 0;
unsigned int L2 = 0;

unsigned int A = 0;
unsigned int B = 0;
unsigned int C = 0;

bool visited[1'000'000] = { false };

std::vector<unsigned int> edges[MAX];

std::vector<int> prefix;
std::vector<int> people;

void bfs(unsigned int vertex) {
    std::queue<unsigned int> queue;
    queue.push(vertex);
    visited[vertex] = true;

    while (queue.empty() == false) {
        unsigned int current = queue.front();
        queue.pop();

        // std::cout << "Current is: " << current << std::endl;

        L2 = L2 - 1;

        for (auto u : edges[current]) {
            if (visited[u] == false) {
                visited[u] = true;
                queue.push(u);
            }
        }
    }
}

void print() {
    std::cout << "Vector is: ";

    for (std::size_t i = 0; i < people.size(); ++i) {
        std::cout << people[i] << ' ';
    }
}

void printPrefix() {
    std::cout << "Prefix is: ";

    for (std::size_t i = 0; i < prefix.size(); ++i) {
        std::cout << prefix[i] << ' ';
    }
}

void printGraph() {
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < edges[i].size(); ++j) {
            std::cout << edges[i][j] << ' ';
        }

        std::cout << std::endl;
    }
}

void connectedComponents() {
    for (unsigned int i = 0; i < N; ++i) {
        // std::cout << "L1 is: " << L1 << std::endl;
        // std::cout << "L2 is: " << L2 << std::endl;

        if (visited[i] == false) {
            bfs(i);
            people.push_back(L1 - L2);
            L1 = L2;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N >> M;

    L1 = N;
    L2 = N;

    for (unsigned int i = 0; i < M; ++i) {
        std::cin >> A >> B;

        edges[A].push_back(B);
        edges[B].push_back(A);
    }

    // printGraph();

    connectedComponents();

    // print();

    /* unsigned int counter = 0;

    for (unsigned int i = 0; i < people.size() - 1; ++i) {
        for (unsigned int j = i + 1; j < people.size(); ++j) {
            counter += people[i] * people[j];
        }
    }

    std::cout << counter << std::endl; */

    unsigned int counter = 0;

    for (unsigned int i = 0; i < people.size(); ++i) {
        if (i == 0) {
            prefix.push_back(people[i]);
        } else {
            unsigned int prev = prefix.back();
            prefix.push_back(people[i] * prev);
        }
    }

    // print();
    // printPrefix();

    for (unsigned int i = 0; i < people.size(); ++i) {
        std::size_t size = prefix.size();
        // std::cout << "Indices are: " << size - 1 << ' ' << i << std::endl;
        counter += people[i] * (prefix[size - 1] - prefix[i]);
        // std::cout << "Prefix are: " << prefix[size - 1] - prefix[i];
        // std::cout << "Counter is: " << counter << std::endl;
    }

    std::cout << counter << std::endl;

    return 0;
}
