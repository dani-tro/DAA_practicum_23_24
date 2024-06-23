#include <iostream>
#include <numeric>

using namespace std;

int arr[102];
int n, a, b;

int dp[102][102];
// n _ a
int main() {
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	for(int i = 0; i <= n; ++i)
		dp[i][0] = 1;


	for (int i = 1; i <= n; ++i) {
		//cout << i << ": ";
		for (int j = 0; j <= b; ++j) {
			dp[i][j] += dp[i - 1][j];
			if (j >= arr[i]) dp[i][j] += dp[i - 1][j - arr[i]];
		//	cout << dp[i][j] << " ";
		}
		//cout <<endl;
	}
	int cnt = 0;
	for(int i = a; i <= b; ++i) {
		cnt += (dp[n][i] > 0);
	}
	cout << cnt;
}
