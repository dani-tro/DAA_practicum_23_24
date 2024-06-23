#include <iostream>
#include <map>
#include <climits>
#include <set>

using namespace std;

#define MAXS 10005
#define MAX 100
long long a, b, n, arr[MAX], sum;
set<long long> s;
long long dp[MAX][MAXS];

int solve()
{
    if (n == 0)
    {
        return 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= sum; ++j)
        {
            if (dp[i - 1][j])
            {
                dp[i][j] = 1;
            }
            if (j >= arr[i])
            {
                dp[i][j] += dp[i - 1][j - arr[i]];
            }
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        dp[i][arr[i]] = 1;
    }

    solve();
    // for (int i = 1; i <= n; ++i)
    // {

    //     for (int j = 0; j <= sum; ++j)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int result{};

    for (int j = a; j <= b; ++j)
    {
        if (dp[n][j])
        {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}