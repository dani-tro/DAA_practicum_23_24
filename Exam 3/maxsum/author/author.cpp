#include <iostream>
#include <limits>
#include <vector>

using namespace std;

const unsigned MAXN = 1000000;
const unsigned MAXK = 1000;
const long long INF = std::numeric_limits<long long>::min();

long long numbers[MAXN];
unsigned int steps[MAXK];
unsigned int n, k;
long long dp_left[MAXN], best_left[MAXN];
long long dp_right[MAXN], best_right[MAXN];

void readInput() {
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	for (int i = 0; i < k; ++i) {
		cin >> steps[i];
	}
}

void solve() {
	dp_left[0] = numbers[0];
	best_left[0] = dp_left[0];

	for (int i = 1; i < n; ++i) {
		dp_left[i] = INF;
		for (int j = 0; j < k; ++j) {
			if (i >= steps[j] && dp_left[i - steps[j]] != INF) {
				dp_left[i] = std::max(dp_left[i], numbers[i] + dp_left[i - steps[j]]);
			}
		}

		best_left[i] = std::max(best_left[i - 1], dp_left[i]);
	}

	dp_right[n - 1] = numbers[n - 1];
	best_right[n - 1] = dp_right[n - 1];

	for (int i = n - 2; i >= 0; --i) {
		dp_right[i] = INF;
		for (int j = 0; j < k; ++j) {
			if (i + steps[j] < n && dp_right[i + steps[j]] != INF) {
				dp_right[i] = std::max(dp_right[i], numbers[i] + dp_right[i + steps[j]]);
			}
		}

		best_right[i] = std::max(best_right[i + 1], dp_right[i]);
	}

	long long best = INF;
	for (int i = 0; i < n - 1; ++i) {
		best = std::max(best, best_left[i] + best_right[i + 1]);
		// cout << i << " --> " << best_left[i] << " " << best_right[i + 1] << " --> " << best_left[i] + best_right[i + 1] << endl;
	}

	std::cout << best << std::endl;
}

int main() {
	readInput();
	solve();
	return 0;
}
