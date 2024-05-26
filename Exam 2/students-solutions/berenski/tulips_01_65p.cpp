#include<bits/stdc++.h>

using namespace std;

#define MAXN 
int n,m;
bool traveled[1000][1000];
int mat[1000][1000];

void dfs(pair<int,int> from,int color){
    if(mat[from.first][from.second] != color)return;
    if(traveled[from.first][from.second])return;
    traveled[from.first][from.second]=true;
    if(from.first!=0) 
    {
        dfs({from.first-1,from.second},mat[from.first][from.second]);
    }
    if(from.first!=n-1) 
    {
        dfs({from.first+1,from.second},mat[from.first][from.second]);
    }
    if(from.second!=0) 
    {
        dfs({from.first,from.second-1},mat[from.first][from.second]);
    }
    if(from.second!=n-1) 
    {
        dfs({from.first,from.second+1},mat[from.first][from.second]);
    }
}
int sol(){
    int ans=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(traveled[i][j])continue;
            dfs({i,j},mat[i][j]);
            ans++;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    cout<<sol()<<endl;
}
