#include <iostream>
using namespace std;
const int MAXN = 2001;
int m = 1e9 + 7;
long long dp[MAXN][MAXN];
int q;
int main()
{
    cin >> q;
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[2][0] = 0;
    dp[2][1] = 0;
    dp[2][2] = 1;
    
    for (int i = 3; i <= q; i++)
    {
        int sum = 0;
        for (int j = 1; j <= i; j++)
        {
            dp[i][0] = 0;
            dp[i][i] = 1;
            for (int k = 1; k <= i-j; k++)
            {
                if (k != j)
                {
                    dp[i][j] += dp[i - j][k];
                }
            }
            dp[i][j] = dp[i][j] % m;
        }

    }
    int sum = 0;
    for (int i = 0; i <= q; i++)
    {
        cout << dp[q][i] << endl;
        sum += dp[q][i];
    }

    cout << sum << endl;
}

