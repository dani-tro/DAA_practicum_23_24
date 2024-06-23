#include<bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define MAXK 105

int n,k;
int stone[MAXN];
int steps[MAXK];

map<pair<int,pair<int,bool>>,long long> dp;

long long solve(int l,int r,bool st){
   
    if(l>=r)return 0;
    if(dp.find({l,{r,st}})!=dp.end())return dp[{l,{r,st}}];
    long long m=LLONG_MIN/2;
    for(int i=1;i<=k;i++)
    {

        m=max(m,solve(l+steps[i],r,0));
        m=max(m,solve(l,r-steps[i],1));
    }
    dp.insert({{l,{r,st}},m+ (st ? stone[r] : stone [l])});
    return m+ (st ? stone[r] : stone [l]);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>stone[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>steps[i];
    }
    long long a=stone[0]+stone[n-1];
    cout<<max(solve(0,n-1,0)+stone[n-1],a);

}