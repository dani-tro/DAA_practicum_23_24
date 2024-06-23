#include <iostream>
#include <vector>

using namespace std;

const int modul = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int S;
    cin >> S;

    vector<vector<int>> dp(S + 1, vector<int>(S + 1, 0));

    for (int i = 1; i <= S; ++i) {
        dp[i][i] = 1;
    }

    for (int i = 1; i <= S; ++i) {
        for (int j = 1; j <= S; ++j) {
            if (dp[i][j] == 0) continue;

            for (int k = 1; k <= S - i; ++k) {
                if (k < j) {
                    dp[i + k][k] = (dp[i + k][k] + dp[i][j]) % modul;
                }
                if (k > j) {
                    dp[i + k][k] = (dp[i + k][k] + dp[i][j]) % modul;
                }
            }
        }
    }

    int result = 0;
    for (int j = 1; j <= S; ++j) {
        result = (result + dp[S][j]) % modul;
    }

    cout << result;
    return 0;
}
