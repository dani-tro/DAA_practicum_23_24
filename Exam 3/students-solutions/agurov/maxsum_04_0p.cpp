#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#define endl '\n'
using namespace std;

char dp[100000][100000];

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
    dp[0][n - 1] = ns[0] + ns[n - 1];

    queue<pair<int, int>> q;
    q.push({ 0,n - 1 });
    int maxSum = dp[0][n - 1];
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;

        q.pop();

        for (auto& x : ks) {
            if (i + x < j) {
                if (dp[i + x][j] < dp[i][j] + ns[i + x]) {
                    dp[i + x][j] = dp[i][j] + ns[i + x];
                    if (maxSum < dp[i + x][j]) {
                        maxSum = dp[i + x][j];
                    }
                    q.push({ i + x, j });
                }
            }
            if (i < j - x) {
                if (dp[i][j - x] < dp[i][j] + ns[j - x]) {
                    dp[i][j - x] = dp[i][j] + ns[j - x];
                    if (maxSum < dp[i][j-x]) {
                        maxSum = dp[i][j-x];
                    }
                    q.push({ i, j - x });
                }
            }
        }
    }
    cout << maxSum << endl;
}