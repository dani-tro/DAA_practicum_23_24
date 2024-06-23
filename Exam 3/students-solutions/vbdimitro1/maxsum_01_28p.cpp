#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 100005;


int N, K;
vector<int> nums;
vector<int> jumps;

long long solve(int delta, int left, int right, bool lastMove)
{
	if (delta <= 0)
	{
		if (lastMove)
			return nums[left];
		else
			return nums[right];
	}

	long long ans = INT_MIN;

	for (int i = 0; i < K; i++)
	{
		ans = max(ans, max(solve(delta - jumps[i], left + jumps[i], right, 0) + nums[left], solve(delta - jumps[i], left, right - jumps[i], 1) + nums[right]));
	}

	return ans;
}

int main()
{

	cin >> N >> K;
	int buff;

	for (int i = 1; i <= N; i++)
	{
		cin >> buff;
		nums.push_back(buff);
	}

	for (int i = 1; i <= K; i++)
	{
		cin >> buff;
		jumps.push_back(buff);
	}

	cout << solve(N - 1, 0, N - 1, 0);

	return 0;
}