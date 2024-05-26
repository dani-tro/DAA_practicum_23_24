#include<bits/stdc++.h>

using namespace std;
#define MAXN 100000
int n;
priority_queue<pair<int,int>> que; 

int dist(pair<int,int> x,pair<int,int> y){
    return (x.first-y.first)*(x.first-y.first) + (x.second-y.second)*(x.second-y.second);
}
long long sol(){
    long long ans;
    pair<int,int> previ=que.top();
    while(!que.empty()){
        pair<int,int> cur=que.top();
        ans+=dist(previ,cur);

        previ=que.top();
        que.pop();
    }
    return ans;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        que.push({x,y});
    }
    cout<<sol();
}
