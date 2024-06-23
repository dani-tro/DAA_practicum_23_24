#include <bits/stdc++.h>

const int MAX_SIZE = 1e5 + 10;
const int MAX_SIZE_K = 1e3 + 10;
int dp[MAX_SIZE], dp2[MAX_SIZE], max2[MAX_SIZE], jumps[MAX_SIZE_K], points[MAX_SIZE];
int n,k;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin>>n>>k;
    for (int i = 1; i <= n; i++) {
        std::cin>>points[i];
    }

    for (int i = 1; i <= k; i++) {
        std::cin>>jumps[i];
    }

    std::fill(max2, max2 + MAX_SIZE, INT_MIN);

    dp[1] = points[1];
    dp2[1] = points[n];
    max2[1] = dp2[1];
    for (int i = 2; i <= n; i++) {
        bool isFound = false;
        for (size_t j = 1; j <= k; j++) {
            if(i - jumps[j] <= 0) {
                continue;
            }
            isFound = true;
            dp[i] = std::max(dp[i], i - jumps[j] >= 0 ? dp[i - jumps[j]] : 0);
            dp2[i] = std::max(dp2[i], i - jumps[j] >= 0 ? dp2[i - jumps[j]] : 0);
        }

        if(isFound) {
            dp[i] += points[i];
            dp2[i] += points[n - i + 1];
        } else {
            dp[i] = INT_MIN / 2;
            dp2[i] = INT_MIN / 2;
        }
        max2[i] = std::max(max2[i-1], dp2[i]);


    }

    // for (size_t i = 1; i <=n ; i++) {
    //     std::cout<<dp[i]<<" ";
    // }
    
    // std::cout<<std::endl;

    // for (size_t i = 1; i <=n ; i++) {
    //     std::cout<<max2[i]<<" ";
    // }

    int maxN = INT_MIN;
    for (size_t i = 1; i <= n; i++) {
        maxN = std::max(maxN, dp[i] + max2[n-i+1]);
    }
    
    std::cout<<maxN<<std::endl;
    return 0;
}