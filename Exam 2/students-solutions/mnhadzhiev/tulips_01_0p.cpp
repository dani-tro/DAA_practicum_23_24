int dfs(int** grid, int src_row, int src_col, bool** visited, int prev_flower, int n, int m) {
    if (src_col >= m
        || src_col < 0
        || src_row >= n
        || src_row < 0) return 0;

    if (visited[src_row][src_col]) return 0;

    if (grid[src_row][src_col] != prev_flower) return 0;

    visited[src_row][src_col] = true;
    dfs(grid, src_row + 1, src_col, visited, grid[src_row][src_col], n, m);
    dfs(grid, src_row - 1, src_col, visited, grid[src_row][src_col], n, m);
    dfs(grid, src_row, src_col + 1, visited, grid[src_row][src_col], n, m);
    dfs(grid, src_row, src_col - 1, visited, grid[src_row][src_col], n, m);
    return 1;
}

int main() {
    int n, m;
    std::cin >> n;
    std::cin >> m;
    int **flowers = new int*[n];
    bool** visited = new bool*[n];
    for (int i = 0; i < n; ++i) {
        visited[i] = new bool[m];
        flowers[i] = new int[m];
    }
//    std::vector<std::vector<int>> flowers;

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            std::cin >> flowers[row][col];
            visited[row][col] = false;
        }
    }
    int total_islands = 0;
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            if (!visited[row][col]) {
                total_islands += dfs(flowers, row, col, visited, flowers[row][col], n, m);
            }
        }
    }

    std::cout << total_islands;

    // deallocate
    for (int i = 0; i < n; ++i) {
        delete[] visited[i];
        delete[] flowers[i];
    }
    delete[] visited;
    delete[] flowers;
    return 0;
}