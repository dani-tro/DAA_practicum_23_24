#include<bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define MAXK 105

int n,k;
int stone[MAXN];
int steps[MAXK];
int ans[MAXN][MAXN];

long long solve(int l,int r,bool st){
   
    if(l>=r)return 0;

    long long m=LLONG_MIN/2;
    for(int i=1;i<=k;i++)
    {

        m=max(m,solve(l+steps[i],r,0));
        m=max(m,solve(l,r-steps[i],1));
    }
    //cout<<l<<" "<<r<<" "<<m<<endl;
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
    cout<<max(solve(0,n-1,0)+stone[n-1],(long long)(stone[0]+stone[n-1]));
}