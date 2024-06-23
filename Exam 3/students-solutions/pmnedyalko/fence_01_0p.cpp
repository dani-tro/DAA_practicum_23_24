#include <bits/stdc++.h>

#define MOD 1000000007;
const int MAX_SIZE = 2048;
long long dp[MAX_SIZE][MAX_SIZE];
int s;
int count = 1;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin>>s;
    for (size_t i = 0; i <= s; i++) {
        dp[1][i] = 1;
    }

    for (size_t i = 2; i <= s; i++) {
        for (size_t j = 1; j < s; j++) {
            if(s - j == j) continue;
            dp[i][j] += dp[i-1][s - j] * dp[1][j];
            dp[i][j] %= MOD;
        }
    }

    // for (size_t i = 0; i <= s; i++) {
    //     for (size_t j = 0; j <= s; j++) {
    //         std::cout<<dp[i][j]<<" ";
    //     }
    //     std::cout<<std::endl;
    // }

    
    long long ans = 0;
    for (size_t i = 1; i <= s; i++) {
        for (size_t j = 1; j < i; j++) {
            ans += dp[i][j];
            ans %= MOD;        
        } 
    }

    std::cout<<ans<<std::endl;
}