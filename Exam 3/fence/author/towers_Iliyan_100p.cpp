#include<iostream>
#define MAXS 5000
using namespace std;
int dp[MAXS+1][MAXS+2][2];
const int mod=1e9+7;
// 0 - prev<curr
// 1 - prev>curr
int main () {
    int s;
    cin >> s ;
    for (int i=0; i<=s+1; i++) {
        dp[0][i][0]=dp[0][i][1]=1;
    }
    for (int i=1; i<=s; i++) {
        for (int j=i; j>=1; j--) {
            dp[i][j][0]=dp[i][j+1][0];
            dp[i][j][0]+=dp[i-j][j-1][1]; dp[i][j][0]%=mod;
        }
        for (int j=1; j<=i; j++) {
            dp[i][j][1]=dp[i][j-1][1];
            dp[i][j][1]+=dp[i-j][j+1][0]; dp[i][j][1]%=mod;
        }
        for (int j=i+1; j<=s; j++) {
            dp[i][j][1]=dp[i][j-1][1];
        }
    }
    cout << ((dp[s][1][0]+dp[s][s][1])%mod+mod-1)%mod ;
    cout << endl ;
    return 0;
}
