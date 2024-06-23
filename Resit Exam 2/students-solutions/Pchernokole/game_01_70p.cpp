#include <iostream>
#include <vector>
#include <queue>
//#include <cmath>
//#include <bits/stdc++.h>
using namespace std;



const int MAX=200005;
vector <pair<int,int>> G [MAX];
queue <int> q;
int P[MAX];//always <=0 :o
bool visited[MAX];
int N, M, K, h1, h2, t, p, helper;

void deij(const int node){
    visited[node]=true;
    q.push(node);
    int n;
    while(!q.empty()){
        n=q.front();
        visited[n]=true;
        q.pop();
        //cout<<n<<endl;
        for(auto i: G[n]){
            P[i.first]=max(P[i.first],P[n]+i.second);
            //cout<<" "<<i.first<<" : "<<P[i.first]<<endl;
            if(visited[i.first]) continue;
            
            q.push(i.first);
        }
    }

    
}


int main () {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    std::cout.tie(NULL);

    cin>>N>>M>>K;
    for(int i=0; i<M; i++){
        cin>>h1>>h2>>p>>t;
        helper=p-t;
        G[h1].push_back(pair<int,int>(h2,helper));
        G[h2].push_back(pair<int,int>(h1,helper));

    }
    
    P[1]=0;
    for(int i=2; i<=N;i++){
        P[i]=-2000000;
    }

    deij(1);

    cout<<K+P[N];

    return 0;
}