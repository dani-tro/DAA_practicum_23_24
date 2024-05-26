#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


bool topoSort(std::vector<std::vector<int>>& graph, int n)
{
    std::vector<int> sorted(n + 1);
    std::queue<int> q;
    std::vector<int> conected(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (auto& u : graph[i])
        {
            conected[u]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (conected[i] == 0) {
            q.push(i);
        }
    }
    int k = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto& u : graph[v])
        {
            conected[u]--;
            if (conected[u] == 0)
            {
                q.push(u);
            }
        }
        sorted[k++] = v;
    }
    if (k != n + 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int K;
    std::cin >> K;
    std::vector<std::vector<int>> graph(20001);
    for (int i = 0; i < K; i++)
    {
        int num;
        std::cin >> num;
        int prev;
        std::cin >> prev;
        for (int i = 0; i < num - 1; i++)
        {
            int after;
            std::cin >> after;
            graph[after].push_back(prev);
            prev = after;
        }
    }
    std::cout << topoSort(graph, 20000);

    return 0;
}