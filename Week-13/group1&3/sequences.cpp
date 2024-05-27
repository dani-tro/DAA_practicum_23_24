# include <bits/stdc++.h>
using namespace std;
const int maxX = 35;
long long dp[maxX][maxX][maxX];
int main(){
    int n, m, k, i, j, p;
    cin >> n >> m >> k;
    //dp[0][][]
    for (j = 0; j <= m; j++)
            dp[0][j][0] = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            //dp[i][j][0]
            for (p = 0; p <= k; p++)
                dp[i][j][0] += dp[i][j-1][p];
            for (p = 1; p <= k; p++)
            {
                dp[i][j][p] = dp[i-1][j][p-1];
            }
        }
    }

    long long ans = 0;
    for (j = 1; j <= m; j++)
        for (p = 1; p <= k; p++)
            ans += dp[n][j][p];
    cout << ans << endl;
}
