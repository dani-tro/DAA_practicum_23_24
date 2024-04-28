#include <algorithm>
#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 1;

int n, k;
int a[MAX_N];

int64_t pr[MAX_N];
int64_t curr_best[MAX_N];

void prefixSums() {
	pr[0] = 0;
	for (int i = 1; i < n; ++i) {
		pr[i] = pr[i - 1] + a[i - 1];
	}
}

int64_t distBetween(int i, int j) { return abs(pr[j] - pr[i]); }

int64_t calcImprovement(int tele, bool first_time = false) {
	int64_t sum = 0;
	for (int i = 0; i < n; ++i) {
		if (first_time) {
			sum += distBetween(i, tele);
		} else {
			sum += min(distBetween(i, tele) - curr_best[i], 0l);
		}
	}
	return sum;
}

void placeTele(int tele, bool override = false) {
	for (int i = 0; i < n; ++i) {
		if (override) curr_best[i] = distBetween(i, tele);
		else curr_best[i] = min(curr_best[i], distBetween(i, tele));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n >> k;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a[i];
	}

	prefixSums();

	int64_t best_imp = 1ll << 62;
	int		best_pos = 0;
	for (int i = 0; i < n; ++i) {
		int64_t imp = calcImprovement(i, true);
		if (imp < best_imp) {
			best_pos = i;
			best_imp = imp;
		}
	}
	placeTele(best_pos, true);

	for (int i = 1; i < k; ++i) {
		int64_t best_imp = 1ll << 62;
		int		best_pos = 0;
		for (int i = 0; i < n; ++i) {
			int64_t imp = calcImprovement(i);
			if (imp < best_imp) {
				best_pos = i;
				best_imp = imp;
			}
		}
		placeTele(best_pos);
	}

	auto i = max_element(curr_best, curr_best + n);
	cout << *i << endl;
	return 0;
}
