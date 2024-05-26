#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<tuple>

long long find(long long v, std::vector<long long>& parents)
{
    if (v != parents[v])
    {
        v = parents[parents[v]];
        find(parents[v], parents);
    }
    else
        return v;
}
void unite(long long v, long long u, std::vector<long long>& parents, std::vector<long long>& sizes)
{
    v = find(v, parents);
    u = find(u, parents);

    if (u == v)
        return;
    else if (sizes[u] > sizes[v])
    {
        parents[v] = u;
        sizes[u] += sizes[v];
    }
    else
    {
        parents[u] = v;
        sizes[v] += sizes[u];
    }
}

void MPD(std::vector<std::tuple<long long, long long, long long>>& graph, long long n, long long counter)
{
    long long answ = 0;
    std::vector<long long> parents(n);
    std::vector<long long> sizes(n);

    for (long long i = 0; i < n; i++)
    {
        parents[i] = i;
        sizes[i] = 1;
    }

    for (long long i = 0; i < counter; i++)
    {
        if (find(std::get<0>(graph[i]), parents) != find(std::get<1>(graph[i]), parents))
        {
            unite(std::get<0>(graph[i]), std::get<1>(graph[i]), parents, sizes);
            answ += std::get<2>(graph[i]);
        }
    }
    std::cout<< answ;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long N;
    std::cin >> N;
    std::vector<std::pair<long long, long long>> coordinates(N);
    std::vector<std::tuple<long long, long long, long long>> graph;
    for (long long i = 0; i < N; i++)
    {
       long long x, y;
        std::cin >> x >> y;
        coordinates[i] = std::pair<long long, long long>(x, y);
    }
    long long counter = 0;
    for (long long i = 0; i < N-1; i++)
    {
        for (long long j = i; j < N; j++)
        {
            long long val = (coordinates[i].first - coordinates[j].first)*(coordinates[i].first - coordinates[j].first) + (coordinates[i].second - coordinates[j].second)*(coordinates[i].second - coordinates[j].second);
            graph.push_back(std::tuple<long long, long long, long long>(i, j, val));
            counter += 1;
        }
    }
    std::sort(graph.begin(), graph.end(), [](std::tuple<long long, long long, long long> lh, std::tuple<long long,long long, long long> rh) {return std::get<2>(lh) < std::get<2>(rh);});
    MPD(graph, N, counter);
    return 0;
}