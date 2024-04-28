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

	long long l = 0, h = n - 1;
	while (a[h] - a[l] > k) {
		if (a[h] - a[l + 1] < a[h - 1] - a[l]) {
			l++;
		}
		else {
			h--;
		}	
	}

	std::cout << h - l + 1 << std::endl;

	return 0;
}