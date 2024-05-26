#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

const int INF = 1000000000;
const int MAX_VERTICES = 100000;

int n, m, k, q;
std::vector<std::pair<int, int>> adj_list[MAX_VERTICES + 1];
bool visited[MAX_VERTICES + 1];
int parent[MAX_VERTICES + 1];
int dist[MAX_VERTICES + 1];

std::vector<int> important;
std::vector<int> questions;
std::vector<std::vector<int>> answers;

std::vector<int> finals;

std::vector<int> dijkstra(int src)
{
        std::fill(dist, dist + n + 1, INF);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty())
        {
            int cur_dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (visited[u])
            {
                continue;
            }
            visited[u] = true;

            for (const std::pair<int, int>& p : adj_list[u])
            {
                int v = p.first;
                int w = p.second;

                if (!visited[v] && cur_dist + w < dist[v])
                {
                    dist[v] = cur_dist + w;
                    pq.push({dist[v], v});
                    parent[v] = u;
                }
            }
        }

        std::vector<int> ans;
        for (size_t i = 0; i <= n; i++)
        {
            ans.push_back(dist[i]);
            //std::cout << i << " " << ans[i] << '\n';
        }

        std::fill(dist, dist + n + 1, INF);
        std::fill(visited, visited + n + 1, false);
        std::fill(parent, parent + n + 1, 0);
        
        return ans;   
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> m;
    for (std::size_t i = 0; i < m; ++i)
    {
        int x, y, t;
        std::cin >> x >> y >> t;
        adj_list[x].push_back({y, t});
        adj_list[y].push_back({x, t});
    }
    
    std::cin >> k;
    for (std::size_t i = 0; i < k; ++i)
    {
        int z;
        std::cin >> z;
        important.push_back(z);
    }
    
    std::cin >> q;
    for (std::size_t i = 0; i < q; ++i)
    {
        int z;
        std::cin >> z;
        questions.push_back(z);
    }

    for (size_t i = 0; i < k; i++)
    {
        std::vector<int> a = dijkstra(important[i]);
        answers.push_back(a);
    }
    
    for (size_t i = 0; i < k - 1; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            //std::cout << answers[i][j] << ' ';
            
            if(answers[i][j] < answers[i + 1][j])
            {
                finals.push_back(answers[i][j]);
            }
            else
            {
                finals.push_back(answers[i + 1][j]);
            }
            
        }
        //std::cout << '\n';
    }
   
    for (size_t i = 0; i < n; i++)
    {
        //std::cout << finals[i] << ' ';
    }
    //std::cout << '\n';
    
    for (size_t i = 0; i < q; i++)
    {
        std::cout << finals[questions[i]] << '\n';
    }
    
}