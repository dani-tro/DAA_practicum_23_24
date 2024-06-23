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
long long best;

void readInput() {
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	for (int i = 0; i < k; ++i) {
		cin >> steps[i];
	}
}

void solve(int left, int right, long long current) {
	if (current > best) {
		best = current;
	}

	for (int i = 0; i < k; ++i) {
		if (left + steps[i] < right) {
			solve(left + steps[i], right, current + numbers[left + steps[i]]);
		}

		if (right - steps[i] > left) {
			solve(left, right - steps[i], current + numbers[right - steps[i]]);
		}
	}
}

int main() {
	readInput();

	best = INF;
	solve(0, n - 1, numbers[0] + numbers[n - 1]);

	cout << best << endl;

	return 0;
}
