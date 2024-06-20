# include <bits/stdc++.h>
using namespace std;
long long p, n, s;
long long counter = 0;
void bruteforce(long long num, long long sum){
    if (num == n){
        if (sum < s) counter ++;
        return ;
    }
    for (long long i = 0; i < p; i++){
        if (sum + i < s)
            bruteforce(num+1, sum + i);
    }
}
long long dp[32][32];

int main(){
    cin >> p >> n >> s;
    //bruteforce (0,0);
    //cout << counter << endl;

    long long i, j, k;
    for (i = 0; i < p; i++) dp[1][i] = 1;
    for (i = 2; i <= n; i++){
        dp[i][0] = 1;
        for (j = 1; j < s; j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - (j-p >= 0 ? dp[i-1][j-p] : 0);
        }
    }
    long long ans = 0;
    for (i = 0; i < s; i++) ans += dp[n][i];
    cout << ans << endl;
return 0;
}
