#include <bits/stdc++.h>

#define MAX 100000

using namespace std;

int n, k;
int dp[100][100];
int seq[MAX];
int moves[1000];

int solve(int l, int r) {
    if (l >= r) return 0;
    int sum = seq[l] + seq[r];
    int diff = r - l;
    int max_sum = 0;
    for (int i = 0; i < k; i++) {
        if (diff > moves[i]) {
            int other_max = max(solve(l + moves[i], r) - seq[r], solve(l, r - moves[i]) - seq[l]);
            max_sum = max(max_sum, other_max);
        }
    }
    //cout << max_sum + sum << endl;
    return max_sum + sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    for (int i = 0; i < k; i++) {
        cin >> moves[i];
    }
    cout << solve(0, n - 1);
}