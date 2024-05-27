#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = n + m;
                dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - 1]);
                dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);

                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};

int main()
{
    Solution sol;
    cout << sol.minDistance("abc", "ac") << '\n';
}
