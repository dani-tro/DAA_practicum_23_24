#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, a, b;
	std::cin >> n >> a >> b;

	std::vector<int> s;
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		s.push_back(x);
	}

	std::vector<bool> dp(b + 1, false);
	dp[0] = true;
	for (int i = 0; i < n; i++) {
		for (int j = b; j >= s[i]; j--) {
			if (dp[j - s[i]] == true) {
				dp[j] = true;
			}
		}
	}

	long long result = 0;
	for (int i = a; i <= b; i++) {
		if (dp[i] == true) {
			result++;
		}
	}

	std::cout << result << std::endl;

	return 0;
}