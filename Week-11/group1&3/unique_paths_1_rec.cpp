class Solution {
public:
    int N, M, dp[128][128];
    int calc(int x, int y)
    {
        if(x == N || y == M)return 1;

        if(dp[x][y])return dp[x][y];
        return dp[x][y] = calc(x + 1, y) + calc(x, y + 1);
    }

    int uniquePaths(int m, int n) {
        M = m;
        N = n;
        return calc(1, 1);
    }
};
