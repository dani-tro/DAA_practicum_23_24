#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MAXN 2000
int n;
long long counter;
long long dp[MAXN][2][MAXN];
long long buidTower(int rem,bool shorter,int h)
{
    if(rem<=0){
        return 1;
    }
    if(dp[rem][shorter][h]!=0)return dp[rem][shorter][h];
    long long sum=0;
    if(shorter)
    {
        for(int i=1;i<h&&i<=rem;i++){
            sum+=buidTower(rem-i,!shorter,i);
        }
    }
    else 
    {
        for(int i=h+1;i<=rem;i++){
            sum+=buidTower(rem-i,!shorter,i);
        }
    }
    return dp[rem][shorter][h]=sum%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    cout<<(buidTower(n,0,0)+buidTower(n,1,n+1)-1)%MOD;
}