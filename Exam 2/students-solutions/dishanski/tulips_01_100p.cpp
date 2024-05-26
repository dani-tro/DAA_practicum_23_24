#include <queue>
#include <vector>

#include <iostream>

struct Pair {
    int first = 0;
    int second = 0;
};

int N = 0;
int M = 0;

int visited[1001][1001] = { false };
int matrix[1001][1001];

std::queue<Pair> queue;

std::vector<Pair> pairs;

bool outRange(int i, int j) {
    return  i < 0 || i == N ||
            j < 0 || j == M;
}

void bfs(int i, int j) {
    queue.push({ i, j });
    visited[i][j] = true;

    while (queue.empty() == false) {
        int index1 = queue.front().first;
        int index2 = queue.front().second;

        // std::cout << "Queue element is: " << index1 << " " << index2 << std::endl;

        queue.pop();

        /* if (visited[index1][index2]) {
            continue;
        } */

        for (int i = 0; i < pairs.size(); ++i) {
            int current1 = index1 + pairs[i].first;
            int current2 = index2 + pairs[i].second;

            // std::cout << "Direction is: " << current1 << current2 << std::endl;

            if (outRange(current1, current2) || visited[current1][current2]) {
                continue;
            }

            if (matrix[index1][index2] == matrix[current1][current2]) {
                queue.push({ current1, current2 });
                visited[current1][current2] = true;
            }
        }
    }
}

unsigned int connectedComponents() {
    unsigned int result = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (visited[i][j] == false) {
                // std::cout << "Current are: " << i << ' ' << j << std::endl;
                result = result + 1;
                bfs(i, j);
            }
        }
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    pairs.push_back({ 0, 1 });
    pairs.push_back({ 1, 0 });
    pairs.push_back({ 0, -1 });
    pairs.push_back({ -1, 0 });

    std::cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> matrix[i][j];
            visited[i][j] = false;
        }
    }

    std::cout << connectedComponents() << std::endl;

    return 0;
}
