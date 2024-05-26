#include<bits/stdc++.h>

using namespace std;

#define MAXM 100005
#define MAXN 300005

long long n,m,q,k;

vector<vector<pair<int,int>>> edges(MAXN);
vector<long long> d(MAXN);
priority_queue<int> que; 
bool traveled[MAXN];

void dijk(int from){

    que.push(from);
    traveled[from]=true;
    for(int i=0;i<n;i++){
        d[i]=INT_MAX/2;
    }
    d[from]=0;

    while(!que.empty()){
        int cur_ed=que.top();
        que.pop();
        traveled[cur_ed]=true;
        for(auto x:edges[cur_ed]){
            if(traveled[x.second])continue;
            que.push(x.second);
            if(d[x.second]>d[cur_ed]+x.first)
            {
                d[x.second]=d[cur_ed]+x.first;
            }

        }
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,w,dist;
        cin>>u>>w>>dist;
        edges[u].push_back({dist,w});
        edges[w].push_back({dist,u});
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int t1;
        cin>>t1;
        edges[n].push_back({0,t1});
        edges[t1].push_back({0,n});
    }
    dijk(n);

    cin>>q;
    vector<int> ans(q);
    for(int i=0;i<q;i++){
        int t1;
        cin>>ans[i];
    }
    for(int i=0;i<q;i++){
        cout<<d[ans[i]]<<endl;
    }
}