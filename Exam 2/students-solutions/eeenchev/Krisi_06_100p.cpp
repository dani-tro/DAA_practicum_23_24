#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>
#include<algorithm>
const long long INF = 10e17;
long long n, m, k, q, i, j, from, to, t, current_node;
int queries[300002];
long long distance[100002];
std::priority_queue<std::pair<int, long long>, std::vector<std::pair<int, long long>>, std::greater<std::pair<int, long long>>> pq;
std::vector<std::pair<int, long long>> graph[100002];

int main(){
    // std::ios_base :: sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::cout.tie(nullptr);

    std::cin >> n >> m;
    for(i = 0; i < n; i++){
        distance[i] = INF;
    }
    for(i = 0; i < m; i++){
        std::cin >> from >> to >> t;
        graph[from].push_back({to, t});
        graph[to].push_back({from, t});
    }

    std::cin >> j;
    for(i = 0; i < j; i++){
        std::cin >> from;
        pq.push({from, 0});
        distance[from] = 0;
    }

    std::cin >> m;
    for(i = 0; i < m; i++){
        std::cin >> queries[i];
    }
    while(!pq.empty()){
        current_node = pq.top().first;
        pq.pop();
        for(auto &&x : graph[current_node]){
            to = x.first;
            t = x.second;
            if(distance[to] > distance[current_node] + t){
                distance[to] = distance[current_node] + t;
                pq.push({to, distance[to]});
            }
        }
    }
    for(i = 0; i < m; i++){
        std::cout << distance[queries[i]] << std::endl;
    }
    return 0;
}