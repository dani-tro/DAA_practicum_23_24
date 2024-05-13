class Solution {
public:
int N, M, dp[128][128];
int calc(int x, int y, vector<vector<int>>& obstacleGrid)
    {
        
        if(x > N - 1 || y > M - 1)return 0;
        if(obstacleGrid[x][y])return 0;
        if(x == N - 1 && y == M - 1)return 1;

        if(dp[x][y])return dp[x][y];
        return dp[x][y] = calc(x + 1, y, obstacleGrid) + calc(x, y + 1,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        N = obstacleGrid.size();
        M = obstacleGrid[0].size();
        return calc(0, 0, obstacleGrid);
    }
};
