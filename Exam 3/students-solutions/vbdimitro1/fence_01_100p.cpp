#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 2004;

long long dp[MAX][MAX][2];
long long pref[MAX][MAX][2];

const long long MOD = 1000000007;


int main()
{
	int s;

	cin >> s;


	for (int i = 1; i <= s; i++)
		dp[i][i][0] = dp[i][i][1] = 1;

	for (int i = 1; i <= s; i++)
	{
		for (int j = 1; j <= i - 1; j++)
		{
			dp[i][j][0] += pref[i - j][j][1];
			dp[i][j][1] += pref[i - j][j][0];
		}
		


		for (int j = 1; j <= s; j++)
		{
			pref[i][j][0] = (pref[i][j - 1][0]+ dp[i][j - 1][0]) % MOD;
		}

		for (int j = s - 1; j >= 0; j--)
		{
			pref[i][j][1] = (pref[i][j + 1][1] + dp[i][j + 1][1]) % MOD;
		}
	}

	long long ans = 1;

	for (int i = 0; i <= s - 1; i++)
	{
		ans = (ans + (dp[s][i][0] + dp[s][i][1]) % MOD) % MOD;
	}

	cout << ans;

	return 0;
}