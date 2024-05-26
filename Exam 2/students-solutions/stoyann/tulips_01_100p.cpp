#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define MAX 1001000
vector<int> g[MAX];
queue<int> q;
bool used[MAX];
int n,m,a,b;
int matrix[1024][1024];

void bfs(int from)
{
    q.push(from);
    
    int node;
    while (!q.empty())
    {
        node=q.front();
        q.pop();
        if(used[node]) continue;
        used[node] = true;

        for(auto u:g[node])
        {
            if(used[u]) continue;
            q.push(u);
        }
    }
}

int components()
{
    int cnt=0;
    for(int i=0;i<n*m;++i)
    {
        if(!used[i])
        {
            ++cnt;
            bfs(i);
        }
    }
    return cnt;
}

int id(int x,int y)
{
    return x*m+y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin >> a;
            matrix[i][j]=a;
        }
    }

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
           if(j < m-1 && matrix[i][j]==matrix[i][j+1])
           {
                g[id(i,j)].push_back(id(i,j+1));
                g[id(i,j+1)].push_back(id(i,j));
           }
           if(i < n-1 && matrix[i][j]==matrix[i+1][j])
           {
                g[id(i,j)].push_back(id(i+1,j));
                g[id(i+1,j)].push_back(id(i,j));
           }
        }
    }

    cout << components() << endl;

    return 0;
}