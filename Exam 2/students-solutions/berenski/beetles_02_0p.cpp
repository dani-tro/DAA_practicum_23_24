#include<bits/stdc++.h>

using namespace std;
int n;
priority_queue<pair<int,int>> que; 

long long dist(pair<int,int> x,pair<int,int> y){
    return (x.first-y.first)*(x.first-y.first) + (x.second-y.second)*(x.second-y.second);
}

long long sol(){
    long long ans=0;
    pair<int,int> previ=que.top();
    que.pop();
    pair<int,int> cur=que.top();
    while(!que.empty()){

        if(dist(previ,cur)>100)
        {
            ans+=dist(previ,cur);
        }
        else {
            vector<pair<int,int>> work;
            while(!que.empty()&&dist(previ,cur)<=100)
            {
                work.push_back(cur);
                cur=que.top();
                que.pop();
            }
            int min=105;
            for(pair<int,int> x : work){
                if(min > dist(previ,x)){
                    min=dist(previ,x);
                }
                que.push(x);
            }
            ans+=min;
        }
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
