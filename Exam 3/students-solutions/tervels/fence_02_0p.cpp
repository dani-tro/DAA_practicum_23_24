#include <iostream>

using namespace std;

const long long MOD = 1'000'000'007,
	MAXS = 2048;
long long s, dp[MAXS][MAXS];

long long calc(long long curr, long long last, bool flag)
{
	if (curr > s) return 0;
	if (curr == s) return 1;

	long long ans = 0;
	if (flag) // iskame po golqmo
	{
		for (int i = last + 1; i <= s - curr; ++i)
			ans = (ans + calc(curr + i, i, false)) % MOD;
	}
	else
	{
		for (int i = 1; i < last; ++i)
			ans = (ans + calc(curr + i, i, true)) % MOD;
	}

	return ans;
}

int main()
{
	cin >> s;

	cout << calc(0, 0, 1) << endl;

	return 0;
}