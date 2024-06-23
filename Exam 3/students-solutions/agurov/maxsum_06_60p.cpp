#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#define endl '\n'
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> ns(n);
	for (auto& x : ns)
		cin >> x;
	vector<int> ks(k);
	for (auto& x : ks)
		cin >> x;
	int** dp = new int* [n - 1];
	for (int i = 0; i < n - 1; i++) {
		dp[i] = new int[n - i - 1];
	}
	dp[0][n - 2] = ns[0] + ns[n - 1];

	queue<pair<int, int>> q;
	q.push({ 0,n - 1 });
	int maxSum = dp[0][n - 2];
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;

		q.pop();

		for (auto& x : ks) {
			if (i + x < j) {
				if (dp[i + x][j - i - 1 - x] < dp[i][j - i - 1] + ns[i + x]) {
					dp[i + x][j - i - 1 - x] = dp[i][j - i - 1] + ns[i + x];
					if (maxSum < dp[i + x][j - i - 1 - x]) {
						maxSum = dp[i + x][j - i - 1 - x];
					}
					q.push({ i + x, j });
				}
			}
			if (i < j - x) {
				if (dp[i][j - x - i - 1] < dp[i][j - i - 1] + ns[j - x]) {
					dp[i][j - x - i - 1] = dp[i][j - i - 1] + ns[j - x];
					if (maxSum < dp[i][j - x - i - 1]) {
						maxSum = dp[i][j - x - i - 1];
					}
					q.push({ i, j - x });
				}
			}
		}
	}
	cout << maxSum << endl;
}