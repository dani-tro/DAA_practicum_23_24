#include <iostream>
#include <vector>
using namespace std;

bool suma(const vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    dp[0][0] = true;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= target; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    
    return dp[n][target];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, a, b;
    cin >> n >> a >> b;
    
    if (a > b) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> num(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    
    int sums = 0;
    for (int j = a; j <= b; ++j) {
        if (suma(num, j)) {
            ++sums;
        }
    }

    cout << sums ;
    
    return 0;
}
