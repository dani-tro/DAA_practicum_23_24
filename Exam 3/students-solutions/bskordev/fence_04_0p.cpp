#include <iostream>
#include <vector>
#include <climits>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> m(k);
	for (int i = 0; i < k; i++) {
		std::cin >> m[i];
	}

	std::vector<int> l(n + 1, INT_MIN);
	std::vector<bool> lVisited(n + 1, false);

	l[1] = a[1];
	lVisited[1] = true;

	for (int i = 2; i <= n - 1; i++) {
		for (int& move : m) {
			if (i - move >= 1 && lVisited[i - move]) {
				lVisited[i] = true;
				l[i] = std::max(l[i], l[i - move] + a[i]);
			}
		}
	}

	for (int i = 2; i <= n - 1; i++) {
		l[i] = std::max(l[i], l[i - 1]);
	}

	std::vector<int> r(n + 1, INT_MIN);
	std::vector<bool> rVisited(n + 1, false);

	r[n] = a[n];
	rVisited[n] = true;

	for (int i = n - 1; i >= 2; i--) {
		for (int& move : m) {
			if (i + move <= n && rVisited[i + move]) {
				rVisited[i] = true;
				r[i] = std::max(r[i], r[i + move] + a[i]);
			}
		}
	}


	for (int i = n - 1; i >= 2; i--) {
		r[i] = std::max(r[i], r[i + 1]);
	}

	int result = INT_MIN;
	for (int i = 1; i <= n - 1; i++) {
		result = std::max(result, l[i] + r[i + 1]);
	}

	std::cout << result << std::endl;

	return 0;
}