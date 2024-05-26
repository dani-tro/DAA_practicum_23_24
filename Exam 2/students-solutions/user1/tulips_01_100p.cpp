#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

void find(std::vector<std::vector<int>>& graph, std::vector<std::vector<bool>>& visited, int n, int m, int i, int j)
{
    std::queue<std::tuple<int, int, int>> q;
    q.push(std::tuple<int, int, int>(i,j,graph[i][j]));
    visited[i][j] = 1;
    while (!q.empty())
    {
        std::tuple<int,int,int> smth = q.front();
        q.pop();
        if (std::get<0>(smth) + 1 < n && graph[std::get<0>(smth) + 1][std::get<1>(smth)] == std::get<2>(smth) && !visited[std::get<0>(smth) + 1][std::get<1>(smth)])
        {
            q.push(std::tuple<int, int, int>(std::get<0>(smth) + 1, std::get<1>(smth), std::get<2>(smth)));
            visited[std::get<0>(smth) + 1][std::get<1>(smth)] = 1;
        }

        if (std::get<1>(smth) + 1 < m && graph[std::get<0>(smth)][std::get<1>(smth) + 1] == std::get<2>(smth) && !visited[std::get<0>(smth)][std::get<1>(smth) + 1])
        {
            q.push(std::tuple<int, int, int>(std::get<0>(smth), std::get<1>(smth) + 1, std::get<2>(smth)));
            visited[std::get<0>(smth)][std::get<1>(smth) + 1] = 1;
        }

        if (std::get<0>(smth) - 1 >= 0 && graph[std::get<0>(smth) - 1][std::get<1>(smth)] == std::get<2>(smth) && !visited[std::get<0>(smth) - 1][std::get<1>(smth)])
        {
            q.push(std::tuple<int, int, int>(std::get<0>(smth) - 1, std::get<1>(smth), std::get<2>(smth)));
            visited[std::get<0>(smth) - 1][std::get<1>(smth)] = 1;
        }

        if (std::get<1>(smth) - 1 >= 0 && graph[std::get<0>(smth)][std::get<1>(smth) - 1] == std::get<2>(smth) && !visited[std::get<0>(smth)][std::get<1>(smth) - 1])
        {
            q.push(std::tuple<int, int, int>(std::get<0>(smth), std::get<1>(smth) - 1, std::get<2>(smth)));
            visited[std::get<0>(smth)][std::get<1>(smth) - 1] = 1;
        }
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> graph(N);
    std::vector<std::vector<bool>> visited(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int smth;
            std::cin >> smth;
            graph[i].push_back(smth);
            visited[i].push_back(0);
        }
    }

    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j])
            {
                find(graph, visited, N, M, i, j);
                counter++;
            }
        }
    }
    std::cout << counter;
    return 0;
}