#include<bits/stdc++.h>
#define MAXS 5007
using namespace std;

int s;
const int mod=1000000007;

int dp[MAXS][MAXS][2];

int main(){

    cin>>s;

    for(int last=1;last<=s;last++){
        dp[0][last][0]=dp[0][last][1]=1;
    }

    for(int sum=1;sum<=s;sum++){
        for(int last=sum-1;last>=0;last--){
            dp[sum][last][0]=dp[sum-(last+1)][last+1][1] + dp[sum][last+1][0];
            dp[sum][last][0]%=mod;
        }
        for(int last=2;last<=s;last++){
            dp[sum][last][1]=dp[sum][last-1][1];
            if(sum-(last-1)>=0)dp[sum][last][1]+=dp[sum-(last-1)][last-1][0];
            dp[sum][last][1]%=mod;
        }
    }

    cout<<(dp[s][0][0]+dp[s][s][1])%mod<<"\n";

    return 0;
}
