#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 105

int n, a, b;
pair<int, int> dp[MAXN];
int numbers[MAXN];

void calc(int i, int sum) {
	if (i >= n) return;
	if (sum > b) return;

	sum += numbers[i];

	if (dp[sum].second <= i && dp[sum].second != -1) {
		return;
	}
	else {
		if (sum >= a && sum <= b) {
			dp[sum] = { 1 , i };
		}
	}

	for (int j = i + 1; j < n; j++) {
		calc(j, sum);
	}

}

int main() {
	cin >> n >> a >> b;

	for (int i = 0; i < MAXN; i++) {
		dp[i] = { 0, -1 };
	}

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	for (int i = 0; i < n; i++) {
		calc(i, 0);
	}

	int ans = 0;

	for (int i = a; i <= b; i++) {
		ans += dp[i].first;
	}


	cout << ans << endl;
	return 0;



}