#include <iostream>
#include <vector>

using namespace std;

const int modul = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int S;
    cin >> S;

    if(S == 0){
        cout << 0;
        return 0;
    }

    vector<int> dp(S + 1, 0);
    vector<int> novo(S + 1, 0);

    for (int i = 1; i <= S; ++i) {
        dp[i] = 1; 
    }

    for (int i = 1; i < S; ++i) {
        fill(novo.begin(), novo.end(), 0);
        for (int j = 1; j <= S; ++j) {
            if (dp[j] == 0) continue;

            for (int k = 1; k <= S - i; ++k) {
                if (k < j) {
                    novo[k] = (novo[k] + dp[j]) % modul;
                }
                if (k > j) {
                    novo[k] = (novo[k] + dp[j]) % modul;
                }
            }
        }
        dp.swap(novo);
    }

    int result = 0;
    for (int j = 1; j <= S; ++j) {
        result = (result + dp[j]) % modul;
    }

    cout << result;
    return 0;
}
