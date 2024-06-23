#include <iostream>
#include <vector>
using namespace std;

const long modul = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int S;
    cin >> S;

    if (S == 0) {
        cout << 0;
        return 0;
    }

    vector<vector<long>> dp(S + 1, vector<long>(S + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= S; ++i) {
        for (int j = 1; j <= i; ++j) {
            for (int k = 1; k <= i; ++k) {
                if (i >= k) {
                    dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) % modul;
                }
            }
        }
    }

    long result = 0;
    for (int j = 1; j <= S; ++j) {
        result = (result + dp[S][j]) % modul;
    }

    cout << result;
    return 0;
}
