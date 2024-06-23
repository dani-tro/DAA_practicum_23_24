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

	int n;
	cin >> n;
	vector<int> dp(n, 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 3;
	dp[4] = 4;
	dp[5] = 9;
	dp[6] = 12;

	cout << dp[n] << endl;
}