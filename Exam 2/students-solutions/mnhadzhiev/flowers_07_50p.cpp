#include <iostream>
#include <vector>
#include <unordered_map>

bool dfs(std::unordered_map<int, std::vector<int>>& grid,
         std::unordered_map<int, bool>& visited,
         int src,
         bool* path) {
    if (path[src]) return false;

    path[src] = true;

    for (int& neighbour : grid[src]) {
        if (visited[neighbour]) continue;

        if (!dfs(grid, visited, neighbour, path)) return false;
    }

    path[src] = false;

    visited[src] = true;

    return true;
}



int main() {
    int friends;
    std::unordered_map<int, std::vector<int>> graph;
    std::unordered_map<int, bool> visited;
    std::cin >> friends;
    int max = -1;
    int first_el = -1;

    for (int i = 0; i < friends; ++i) {

        int flowers_count;
        std::cin >> flowers_count;

        int prev = -1;
        int current;

        for (int j = 0; j < flowers_count; ++j) {
            std::cin >> current;

            if (current > max) {
                max = current;
            }

            if (first_el == -1) {
                first_el = current;
            }

            if (prev != -1) {
                graph[prev].push_back(current);
            }
            prev = current;
        }
    }

    bool* path = new bool[max + 1];
    for (int i = 0; i < max + 1; ++i) {
        path[i] = false;
    }
    bool has_loop = !dfs(graph, visited, first_el, path);

    std::cout << (has_loop ? 0 : 1);

    delete[] path;
    return 0;
}
