#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define MAX 100100

vector<pair<int,int>> g[MAX];
bool used[MAX];
priority_queue<pair<int,int>> pq;
int n,m,x,y,t,d[MAX],k,q;

void dijkstra(int from)
{
    fill(d,d+n+1,INT_MAX/2);
    fill(used,used+n+1,false);

    d[from]=0;
    pq.push({d[from],from});

    int node,u,w;

    while(!pq.empty())
    {
        node=pq.top().second;
        pq.pop();
        if(used[node]) continue;
        used[node]=true;

        for(auto e:g[node])
        {
            u=e.first;
            w=e.second;

            if(d[u]>d[node]+w)
            {
                d[u]=d[node]+w;
                pq.push({-d[u],u});
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<m;++i)
    {
        cin >> x >> y >> t;
        g[x].push_back({y,t});
        g[y].push_back({x,t});
    }

    cin >> k;
    for(int i=0;i<k;++i)
    {
        cin >> x;
        g[n].push_back({x,0});
    }
    dijkstra(n);

    cin >> q;
    for(int i=0;i<q;++i)
    {
        cin >> x;
        cout << d[x] << endl;
    }

    return 0;
}