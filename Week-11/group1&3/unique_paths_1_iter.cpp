class Solution {
public:
    int N, M, dp[128][128];
    
    int uniquePaths(int m, int n) {
    	
        for(int i = 1; i <= n; i++)dp[1][i] = 1;
        for(int i = 1; i <= m; i++)dp[i][1] = 1;
        for(int j = 2; j <= m; j++)
        {
            for(int i = 2; i <= n; i++)dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
        }
        return dp[m][n];
    }
};
