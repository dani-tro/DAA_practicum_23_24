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

long long solve(int delta, int left, int right)
{
	long long ans = LLONG_MIN;
	long long leftSum;
	long long rightSum;
	int newDelta;

	for (int i = 0; i < K; i++)
	{
		newDelta = delta - jumps[i];

		if (newDelta <= 0)
			return nums[left] + nums[right];

		ans = max(ans, max(solve(delta - jumps[i], left + jumps[i], right) + nums[left], solve(delta - jumps[i], left, right - jumps[i]) + nums[right]));
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

	cout << max(solve(N - 1, 0, N - 1), (long long)(nums[0] + nums[N - 1]));

	return 0;
}