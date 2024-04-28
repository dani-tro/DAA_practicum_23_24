#include <iostream>
#include <vector>
#include <climits>

bool isSolvable(std::vector<long long> const& d, long long k, long long key) {
	long long n = d.size() + 1;

	long long currD = 0;
	long long currTV = 0;

	long long currDist = LLONG_MAX;

	while (currTV < k) {
		while (currD < n - 1 && currDist <= key) {
			currDist += d[currD];
			currD++;
		}

		if (currD == n - 1) {
			return true;
		}

		currDist = 0;
		while (currD < n - 1 && currDist + d[currD] <= key) {
			currDist += d[currD];
			currD++;
		}

		if (currD == n - 1) {
			return true;
		}

		currTV++;
		currDist = 0;
	}

	while (currD < n - 1 && currDist <= key) {
		currDist += d[currD];
		currD++;
	}

	if (currD == n - 1) {
		return true;
	}

	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	long long n, k;
	std::cin >> n >> k;

	std::vector<long long> d;
	for (int i = 0; i < n - 1; i++) {
		long long di;
		std::cin >> di;

		d.push_back(di);
	}

	long long result = -1;

	long long l = 0, h = (n - 1) * 1e9;
	while (l <= h) {
		long long mid = (l + h) / 2;
		if (!isSolvable(d, k, mid)) {
			l = mid + 1;
		}
		else {
			h = mid - 1;
			result = mid;
		}
	}
	
	std::cout << result << std::endl;

	return 0;
}