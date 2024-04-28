#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

long n, k, a[MAXN], ans;

long calc(long len) {
	long startIdx = 0;
	long endIdx = len - 1;
	long optDiff = INT_MAX;
	while (endIdx < n) {
		optDiff = min(optDiff, (a[endIdx] - a[startIdx]));
		startIdx++;
		endIdx++;
		if (optDiff <= k) break;
	}
	return optDiff;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; i++)  cin >> a[i];
	sort(a, a + n);

	long l = 1, r = n;
	while (l <= r) {
		long startIdx = 0;
		long mid = l + (r - l) / 2;
		long f = calc(mid);
		if (f > k) r = mid - 1;
		else {
			l = mid + 1;
			ans = max(ans, mid);
		}
	}

	cout << ans << endl;
	return 0;
}