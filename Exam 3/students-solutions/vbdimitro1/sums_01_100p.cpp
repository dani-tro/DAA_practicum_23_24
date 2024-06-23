#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 102;

bool dp[MAX][MAX];

int main()
{
	int n, a, b;

	cin >> n >> a >> b;

	int arr[MAX];

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= b; j++)
		{
			if (dp[i - 1][j] && j + arr[i] <= b)
				dp[i][j + arr[i]] = 1;

			if (dp[i - 1][j])
				dp[i][j] = 1;
		}
	}

	long long ans = 0;

	for (int i = a; i <= b; i++)
		ans += dp[n][i];

	cout << ans;

	return 0;
}