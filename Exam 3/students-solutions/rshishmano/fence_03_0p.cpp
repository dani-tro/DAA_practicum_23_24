#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const long modul = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int S;
    cin >> S;

    vector<vector<int>> dp(S + 1, vector<int>(S + 1, 0));
    vector<vector<int>> suma(S + 1, vector<int>(S + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= S; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = (suma[i - j][j - 1] + suma[i - j][S]) % modul;
        }
        for (int j = 0; j <= S; ++j) {
            suma[i][j] = (suma[i - 1][j] + dp[i][j]) % modul;
        }
    }

    int result = 0;
    for (int j = 1; j <= S; ++j) {
        result = (result + dp[S][j]) % modul;
        //cout << result << "\n";
    }

    cout << result << endl;
    return 0;
}

