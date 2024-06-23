#include <iostream>
#include <vector>

int n, a, b;

using namespace std;

bool between(int c) {
	return c <= b && c >= a;
}

int main()
{
	cin >> n >> a >> b;
	vector<int> arr(n);

	for (auto& el : arr) cin >> el;

	vector<vector<int>> dp(n, vector<int>(b+1));

	for (int i = 0; i < n; i++) {
		if (arr[i] <= b) {
			dp[i][arr[i]]++;
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= b; j++) {
			dp [i][j] += dp[i-1][j];
			if (dp[i-1][j] > 0 && j + arr[i] <= b) {
				dp[i][j + arr[i]]++;
			}
		}
	}

	int ctn = 0;
	for (int i = a; i <= b; i++) {
		if (dp[n - 1][i]) ctn++;
	}
	cout << ctn;
}