#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

bool dfs(std::unordered_map<int, std::vector<int>> const &graph, std::vector<bool> &seen, int current){

    if(seen[current]) return false;

    seen[current] = true;
    for(int adj : graph.at(current))
        if(!dfs(graph, seen, adj)) return false;

    return true;

}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    size_t K;
    std::cin >> K;

    std::vector<std::vector<int>> arrays(K);
    std::unordered_map<int, std::vector<int>> graph;
    std::unordered_set<int> unique;

    int min = INT32_MAX;

    for(size_t i = 0; i < K; ++i){

        size_t N;
        std::cin >> N;

        int number;
        std::cin >> number;

        min = std::min(min, number);

        unique.insert(number);
        arrays[i].push_back(number);

        for(size_t j = 1; j < N; ++j){

            int number;
            std::cin >> number;

            unique.insert(number);
            arrays[i].push_back(number);
            graph[arrays[i][j - 1]].push_back(number);

        }

    }

    std::vector<bool> seen(unique.size(), false);

    std::cout << dfs(graph, seen, min) << '\n';

    return 0;
}