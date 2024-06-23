#include <bits/stdc++.h>

using namespace std;
const int MAX = 101;

bool dp[MAX][MAX];
int A[MAX];

int n, a, b;
int ans = 0;

void solve() {
    int max_sum = a;

    for (int i = 1; i < n; ++i) {
        // if (max_sum == b) return;
        if (A[i] <= b) dp[i][A[i]] = true;
        for (int j = 1; j <= n; ++j) {
            if (j + A[i] <= b) {
                dp[i][j + A[i]] = dp[i-1][j];
                //max_sum = dp[j + A[i]] > 0 ? j + A[i] : max_sum;
            }
            dp[i][j] |= dp[i-1][j];
        }

    }
}

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    cin >> n >> a >> b;
    for (int i = 1; i < n; ++i) {
        cin >> A[i];
    }

    solve();

    for (int i = 1; i <= 7; ++i) {
        for (int j = 1; j <= 12; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    for (int s = a; s <= b; ++s) {
        ans += (int)dp[n-1][s];
    }

    cout << ans;

    return 0;
}


//7 11 12
//10 8 2 3 10 5 5

//7 3 6
//10 8 2 3 10 5 5