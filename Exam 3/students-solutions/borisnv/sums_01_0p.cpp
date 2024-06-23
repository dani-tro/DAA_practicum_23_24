#include <iostream>
#include <numeric>

using namespace std;

int arr[100];
int n, a, b;

int dp[100][100];
	// n _ a
int main() {
	cin >> n >> a >> b;
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	
	dp[0][0] = 1;

	for(int i = 1; i < n; ++i) {
		for(int j = 0; j <= b; ++j) {
			dp[i][j] += dp[i-1][j];
			if(j >= arr[i])
				dp[i][j] = dp[i-1][j-arr[i]];
//			cout << dp[i][j] << " ";
		}
//		cout <<endl;
	}

	cout << std::accumulate(dp[n-1] + a, dp[n-1] + b + 1, 0) << endl;
	

}