#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	long long n, k;
	std::cin >> n >> k;

	std::vector<long long> a;

	for (int i = 0; i < n; i++) {
		long long x;
		std::cin >> x;

		a.push_back(x);
	}
	std::sort(a.begin(), a.end());
	
	long long result = 0;

	long long l = 0, h = 0;
	
	while (h < n) {
		while (a[h] - a[l] > k) {
			l++;
		}

		if (result < h - l + 1) {
			result = h - l + 1;
		}

		h++;
	}

	std::cout << result << std::endl;

	return 0;
}