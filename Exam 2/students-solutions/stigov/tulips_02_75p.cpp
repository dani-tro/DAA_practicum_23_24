#include <bits/stdc++.h>
using namespace std;

int n, m;
int A[1003][1003];

struct Point
{
    int x, y;
};


void bfs(Point s)
{
    int color = A[s.x][s.y];
    queue<Point> pq;
    pq.push(s);
    // A[s.x][s.y] = 0;

    while(!pq.empty())
    {
        Point t = pq.front();
        pq.pop();
        A[t.x][t.y] = 0;

        if(t.x > 0 && A[t.x-1][t.y] == color)
        {
            pq.push({t.x-1,t.y});
        }
        if(t.x < n-1 && A[t.x+1][t.y] == color)
        {
            pq.push({t.x+1,t.y});
        }
        if(t.y > 0 && A[t.x][t.y-1] == color)
        {
            pq.push({t.x,t.y-1});
        }
        if(t.y < m-1 && A[t.x][t.y+1] == color)
        {
            pq.push({t.x,t.y+1});
        }
    }

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            cin >> A[i][j];
        }
    }

    int cnt =0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            if(A[i][j] != 0)
            {
                cnt++;
                bfs({i,j});
            }
        }
    }

    cout << cnt;
}