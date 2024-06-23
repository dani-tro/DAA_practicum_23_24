#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

long malkoto = -1000000000;


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

    vector<vector<int>> dp(N, vector<int>(N, malkoto));
    dp[0][N-1] = duska[0] + duska[N-1];
    
   
    for (int left = 0; left < N; ++left) {
        for (int right = N - 1; right > left; --right) {
            if (dp[left][right] == malkoto) continue;
            for (int move : hodove) {
                if (left + move < right) {
                    dp[left + move][right] = max(dp[left + move][right], dp[left][right] + duska[left + move]);
                }
                if (right - move > left) {
                    dp[left][right - move] = max(dp[left][right - move], dp[left][right] + duska[right - move]);
                }
            }
        }
    }
    int max_sum = malkoto;
    for (int left = 0; left < N; ++left) {
        for (int right = N - 1; right > left; --right) {
            max_sum = max(max_sum, dp[left][right]);
        }
    }

    cout << max_sum << endl;
    return 0;
}



