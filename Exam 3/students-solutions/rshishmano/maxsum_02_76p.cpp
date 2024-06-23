#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> duska(N);
    for (int i = 0; i < N; ++i) {
        cin >> duska[i];
    }

    vector<int> hodove(K);
    for (int i = 0; i < K; ++i) {
        cin >> hodove[i];
    }

    vector<int> left_dp(N, INT_MIN);
    vector<int> right_dp(N, INT_MIN);
    
    left_dp[0] = duska[0];
    right_dp[N-1] = duska[N-1];

    for (int i = 0; i < N; ++i) {
        if (left_dp[i] != INT_MIN) {
            for (int hod : hodove) {
                if (i + hod < N) {
                    left_dp[i + hod] = max(left_dp[i + hod], left_dp[i] + duska[i + hod]);
                }
            }
        }
    }

    for (int i = N - 1; i >= 0; --i) {
        if (right_dp[i] != INT_MIN) {
            for (int move : hodove) {
                if (i - move >= 0) {
                    right_dp[i - move] = max(right_dp[i - move], right_dp[i] + duska[i - move]);
                }
            }
        }
    }

    int max_sum = INT_MIN;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (left_dp[i] != INT_MIN && right_dp[j] != INT_MIN) {
                max_sum = max(max_sum, left_dp[i] + right_dp[j]);
            }
        }
    }

    cout << max_sum << endl;
    return 0;
}
