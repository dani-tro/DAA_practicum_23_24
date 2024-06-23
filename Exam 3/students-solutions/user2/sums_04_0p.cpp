#include <bits/stdc++.h>

using namespace std;
const int MAX = 101;

int dp[MAX];
int A[MAX];

int n, a, b;
int ans = 0;

void solve() {
    int max_sum = a;

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j + A[i] <= b)
                dp[j + A[i]] |= dp[j];
        }
        dp[A[i]] = 1;

        for (int j = 1; j <= 13; ++j) {
            cout << dp[j] << " ";
        }
        cout << endl;
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


    for (int s = a; s <= b; ++s) {
        ans += dp[s];
    }

    cout << ans;

    return 0;
}


//7 11 12
//10 8 2 3 10 5 5