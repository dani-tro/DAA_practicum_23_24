#include <iostream>
#include <limits>
#include <vector>

using namespace std;

const unsigned MAXN = 1000000;
const unsigned MAXK = 1000;
const long long INF = std::numeric_limits<long long>::min();

long long numbers[MAXN];
int steps[MAXK];
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

	std::cout << best_left[n - 2] + numbers[n - 1] << std::endl;
}

int main() {
	readInput();
	solve();
	return 0;
}
