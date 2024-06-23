#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 105

int n, a, b, dp[MAXN];
int numbers[MAXN];

void calc(int i, int sum) {
	if (i >= n) return;
	if (sum > b) return;

	sum += numbers[i];

	if (sum >= a && sum <= b) {
		dp[sum] = 1;
	}

	for (int j = i + 1; j < n; j++) {
		calc(j, sum);
	}

}

int main() {
	cin >> n >> a >> b;

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	for (int i = 0; i < n; i++) {
		calc(i, 0);
	}

	int ans = 0;

	for (int i = a; i <= b; i++) {
		ans += dp[i];
	}


	cout << ans << endl;
	return 0;



}