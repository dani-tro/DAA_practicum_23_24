#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

bool binSearch1(int l, int h, int goal, std::vector<int>& smth)
{
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (smth[mid] == goal)
        {
            return true;
        }
        else if (smth[mid] < goal)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return false;
}

void djikstra(std::vector<std::vector<std::pair<int, int>>>& graph, int n, int start, std::vector<int>& important, int k)
{
    std::vector<int> distances(n, 100000);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> S;

    distances[start] = 0;
    S.push(std::pair<int,int>(0, start));

    while (!S.empty())
    {
        std::pair<int, int> v = S.top();
        S.pop();
        if (binSearch1(0, k, v.second, important))
        {
            std::cout << v.first;
            return;
        }

        for (auto& u : graph[v.second])
        {
            if (distances[u.first] > distances[v.second] + u.second)
            {
                distances[u.first] = distances[v.second] + u.second;
                S.push(std::pair<int, int>(distances[u.first], u.first));
            }
        }
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<std::pair<int, int>>> graph(N);
    for (int i = 0; i < M; i++)
    {
        int fst, scnd, third;
        std::cin >> fst >> scnd >> third;
        graph[fst].push_back(std::pair<int, int>(scnd, third));
        graph[scnd].push_back(std::pair<int, int>(fst, third));
    }
    std::vector<int> important;
    int K;
    std::cin >> K;
    for (int i = 0; i < K; i++)
    {
        int place; std::cin >> place;
        important.push_back(place);
    }
    std::sort(important.begin(), important.end());

    int Q;
    std::cin >> Q;
    std::vector<int> questions(Q);
    for (int i = 0; i < Q; i++)
    {
        int question;
        std::cin >> question;
        questions[i] = question;
    }
    for (int i = 0; i < Q; i++)
    {
        djikstra(graph, N, questions[i], important, K);
        std::cout << std::endl;
    }
    return 0;
}