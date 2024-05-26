#include <iostream>
#include <vector>
#include <unordered_map>

bool dfs(std::unordered_map<int, std::vector<int>>& grid,
         std::unordered_map<int, bool>& visited,
         int src,
         std::vector<int> path) {

    for (int& el : path) {
        if (el == src) return false;
    }

    if (visited[src]) return true;

    path.push_back(src);

    visited[src] = true;

    for (int& neighbour : grid[src]) {
        if (!dfs(grid, visited, neighbour, path)) return false;
    }

    path.pop_back();
    return true;
}



int main() {
    int friends;
    std::unordered_map<int, std::vector<int>> graph;
    std::unordered_map<int, bool> visited;
    std::cin >> friends;
    int max = INT_MIN;
    int first_el = -1;
    for (int i = 0; i < friends; ++i) {
        int flowers_count;
        std::cin >> flowers_count;
        int prev = -1;
        int current;
        for (int j = 0; j < flowers_count; ++j) {
            std::cin >> current;
            if (first_el == -1) {
                first_el = current;
            }
            visited[current] = false;
            if (current > max) {
                max = current;
            }
            if (prev != -1) {
                graph[prev].push_back(current);
            }
            prev = current;
        }
    }
    std::vector<int> current_path;

    bool has_loop = !dfs(graph, visited, first_el, current_path);

    std::cout << (has_loop ? 0 : 1);

    return 0;
}
