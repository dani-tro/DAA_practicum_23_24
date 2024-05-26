#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 20010
vector<int> g[MAX];
int k,f,x,y,curr[MAX],in[MAX],maxF,visited,idx,used[MAX];
int flowers[MAX];
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    fill(in,in+MAX,-1);

    cin >> k;
    for(int i=0;i<k;++i)
    {
        cin >> f;
        for(int j=0;j<f;++j)
        {
            cin >> x;
            curr[j]=x;
            //if(maxF<x)
              //  maxF=x;
            if(in[x]==-1)
            {
                in[x]=0;
                flowers[idx]=x;
                idx++;
            }
        }
        for(int j=0;j<f-1;++j)
        {
            g[curr[j]].push_back(curr[j+1]);
            in[curr[j+1]]++;
        }
    }
    
    for(int i=0;i<idx;++i)
    {
        if(in[flowers[i]]==0)
            q.push(flowers[i]);

        //cout << flowers[i] << ' ' << in[flowers[i]] << endl;
    }

    int node;
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        used[node]=true;
        visited++;
        //cout << node << endl;

        for(auto u:g[node])
        {
            if(used[u]) continue;
            --in[u];
            if(in[u]==0)
                q.push(u);
        }
    }

    if(visited < idx-1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
    }

    return 0;
}