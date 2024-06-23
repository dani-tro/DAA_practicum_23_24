#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 10005

int n, k;
int numbers[MAXN];
pair<int, bool> dp[MAXN][MAXN];
int steps[MAXN];
int ans;

void calc(int left, int right, int sum, int moved) {
	if (left >= right) return;
	

	if (moved == 1) {
		sum = sum + numbers[left];
	}
	else if (moved == 2) {
		sum = sum + numbers[right];
	}
	else {
		sum = sum + numbers[left] + numbers[right];
	}

	if (dp[left][right].second == true && dp[left][right].first >= sum) return;

	if (dp[left][right].second == false) {
		dp[left][right] = { -2002, true };
	}
	dp[left][right].first = max(dp[left][right].first, sum);
	ans = max(ans, dp[left][right].first);

	for (int i = 0; i < k; i++) {
		calc(left + steps[i], right, sum, 1);
		calc(left, right - steps[i], sum, 2);
	}
}

int main() {
	cin >> n >> k;

	ans = -2002;

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	for (int i = 0; i < k; i++) {
		cin >> steps[i];
	}

	calc(0, n - 1, 0, 0);
	
	cout << ans << endl;
	return 0;


}