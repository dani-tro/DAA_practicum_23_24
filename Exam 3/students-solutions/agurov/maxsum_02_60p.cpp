#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#define endl '\n'
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> ns(n);
    for (auto& x : ns)
        cin >> x;
    vector<int> ks(k);
    for (auto& x : ks)
        cin >> x;
    vector<vector<int>> dp(n, vector<int>(n, INT16_MIN));
    dp[0][n - 1] = ns[0] + ns[n - 1];

    queue<pair<int, int>> q;
    q.push({ 0,n - 1 });

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;

        q.pop();

        for (auto& x : ks) {
            if (i + x < j) {
                if (dp[i + x][j] < dp[i][j] + ns[i + x]) {
                    dp[i + x][j] = dp[i][j] + ns[i + x];
                    q.push({ i + x, j });
                }
            }
            if (i < j - x) {
                if (dp[i][j - x] < dp[i][j] + ns[j - x]) {
                    dp[i][j - x] = dp[i][j] + ns[j - x];
                    q.push({ i, j - x });
                }
            }
        }
    }
    int maxSum = INT16_MIN;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            maxSum = max(maxSum, dp[i][j]);
        }
    }
    cout << maxSum << endl;
}