#include<bits/stdc++.h>
#define MAXS 5007
using namespace std;

int s;
const int mod=1000000007;

int dp[MAXS][MAXS][2];
bool li[MAXS][MAXS][2];

int ff(int sum,int last,int flag){
    if(sum==0)return 1;

    if(li[sum][last][flag])return dp[sum][last][flag];
    li[sum][last][flag]=true;

    if(flag==0){
        for(int i=last+1;i<=sum;i++){
            dp[sum][last][flag]+=ff(sum-i,i,1);
            dp[sum][last][flag]%=mod;
        }
    }else{
        for(int i=min(last-1,sum);i>=1;i--){
            dp[sum][last][flag]+=ff(sum-i,i,0);
            dp[sum][last][flag]%=mod;
        }
    }

    return dp[sum][last][flag];
}

int main(){

    cin>>s;
    cout<<(ff(s,0,0)+ff(s,s,1))%mod<<"\n";

    return 0;
}