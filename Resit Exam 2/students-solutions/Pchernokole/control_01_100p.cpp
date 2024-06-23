#include <iostream>
#include <vector>
//#include <cmath>
//#include <bits/stdc++.h>
using namespace std;

const int MAX=1000005;
vector <int> G [MAX];
int components [MAX];
int currComp=1;
bool visited [MAX];
long long sum=0;
long long allCurCompNodes=0;
int N, M, h1, h2;

void dfs(const int node, const int comp){
    visited[node]=true;
    components[comp]++;
    for(auto i: G[node]){
        if(!visited[i]){
            dfs(i,comp);
        }
    }
}


int main () {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    std::cout.tie(NULL);

    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>h1>>h2;
        G[h1].push_back(h2);
        G[h2].push_back(h1);

    }
    
    for(int i=0; i<N; i++){
        if(!visited[i]){
            dfs(i,currComp);
            allCurCompNodes+=components[currComp];
            sum+=components[currComp]*(N-allCurCompNodes);
            currComp++;

        }
    }

    cout<<sum;

    return 0;
}