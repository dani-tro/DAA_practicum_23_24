#include<bits/stdc++.h>
#define MAXS 5007
using namespace std;

int s;
const int mod=1000000007;

int dp[MAXS][MAXS][2];
bool li[MAXS][MAXS][2];

int ff(int sum,int last,int flag){
    if(sum==0)return 1;
    if(flag==0 and last>=sum)return 0;
    if(flag==1 and last<=1)return 0;

    if(li[sum][last][flag])return dp[sum][last][flag];
    li[sum][last][flag]=true;

    if(flag==0){
        dp[sum][last][flag]=ff(sum-(last+1),last+1,1) + ff(sum,last+1,0);
        dp[sum][last][flag]%=mod;
    }else{
        dp[sum][last][flag]=ff(sum-(last-1),last-1,0) + ff(sum,last-1,1);
        dp[sum][last][flag]%=mod;
    }

    return dp[sum][last][flag];
}

int main(){

    cin>>s;
    cout<<(ff(s,0,0)+ff(s,s,1))%mod<<"\n";

    return 0;
}
