#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
const int MAX = 1e5 + 5;

struct point
{
    int x;
    int y;
};

std::vector<int> adj[MAX];
bool visited[MAX];
point p[MAX];

int costs[MAX];

void dfs(int u)
{
    visited[u] = true;
    std::cout << u << " " << p[u].x << " " << p[u].y << '\n';

    for (int v : adj[u])
    {
        if (!visited[v])
        {
            /*
            int s = (p[u].x - p[v].x) * (p[u].x - p[v].x) + (p[u].y - p[v].y) * (p[u].y - p[v].y);
            std::cout << 's' << ' ' << s << '\n';
            if(s < costs[u])
            {
                costs[u] = s;
            }
            */
           std::cout << v;

            dfs(v);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    std::cin >> n;

    for (std::size_t i = 0; i < n; ++i)
    {
        int x = 0;
        int y = 0;
        std::cin >> x;
        std::cin >> y;
        p[i].x = x;
        p[i].y = y;
    }

    for (int u = 0; u < n; ++u)
    {
        if (!visited[u])
        {
            dfs(u);
        }
    }

    std::cout << "__________\n";
    for (size_t i = 0; i < n; i++)
    {
        std::cout << costs[i] << ' ';
    }
    
}
    
    
