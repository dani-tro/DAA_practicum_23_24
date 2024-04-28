#include <ios>
#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 1;

int n, k;
int a[MAX_N];

int64_t pr[MAX_N];

void prefixSums() {
	pr[0] = 0;
	for (int i = 1; i < n; ++i) {
		pr[i] = pr[i - 1] + a[i - 1];
	}
}

bool canBeDone(int64_t suggestion) {
	int64_t lastTele;
	int i = 0;
	int teles = 0;
	for(; i <= n; ++i) {
		if(pr[i] > suggestion) {
			lastTele = pr[i-1];
			teles = 1;
			break;
		}
	}
	//cout << "tele: " << lastTele << endl;
	for(;i <=n && pr[i] - lastTele <= suggestion ; ++i) {}
	int64_t firstNotCovered = pr[i];

	for(; i <= n; ++i) {
		for(; i <=n && pr[i] - firstNotCovered <= suggestion; ++i){};
		++teles;
		lastTele = pr[i-1];
		//cout << "tele: " << lastTele << endl;
		for(; i <=n && pr[i] - lastTele <= suggestion; ++i){};
		firstNotCovered = pr[i];
	}
	//cout << "suggestion: " << suggestion << " teles: " << teles <<endl;
	return teles <= k;
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

	int64_t min = 0;
	int64_t max = pr[n-1];
	//cout << "max: " << max << endl;
	while(min != max) {
		int64_t mid = min + ((max - min) >> 1);
		if(canBeDone(mid)) {
			max = mid;
		}
		else min = mid + 1;
	}
	cout << min << endl;
	return 0;
}
