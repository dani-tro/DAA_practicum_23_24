#include <bits/stdc++.h>
using namespace std;

vector<int> g[20004];
int in[20004];

set<int> f; 

bool toposort()
{
    int cnt = 0;
    queue<int> pq;

    for(int l : f)
    {
        for(int v: g[l])
        {
            in[v]++;
        }
    }

    for(int l:f)
    {
        if(in[l] == 0)
        {
            pq.push(l);
        }
    }

    while(!pq.empty())
    {
        int l = pq.front();
        pq.pop();
        cnt++;
        for(int v: g[l])
        {
            in[v]--;
            if(in[v] == 0)
            {
                pq.push(v);
            }
        }
    }

    return cnt == f.size();
   
}
int k;
int main()
{
    cin >> k;
    
    for(int i = 0; i < k; i++)
    {
        vector<int> t;
        int s;
        cin >> s;
        for(int j = 0; j < s; j++)
        {
            int el;
            cin >> el;
            t.push_back(el);
            f.insert(el);
        }
        for(int j = 0; j < t.size()-1; j++)
        {
            g[t[j]].push_back(t[j+1]);
        }
    }

    cout << toposort();

    // for(auto l: f)
    // {
    //     cout << l << " ";
    // }
}