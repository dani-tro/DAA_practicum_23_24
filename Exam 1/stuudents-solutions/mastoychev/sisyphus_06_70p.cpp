#include <iostream>>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

const int MAX_SIZE = 1000000;

long long A[MAX_SIZE];

pair<int, int> paths[2 * MAX_SIZE];

long sums[MAX_SIZE];


int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int l, r;
	long result = 0;
	for (int i = 0; i < 2 * m; i = i + 2) {
		cin >> l >> r;
		for (int j = l-1; j <= r-1; j++) {
			result += A[j];
		}
		paths[i].first = l-1;
		paths[i].second = -1;
		paths[i + 1].first = r-1;
		paths[i + 1].second = 1;
	}

	for (int i = 0; i < n; i++) {
		sums[i] = 0;
	}
	sort(paths, paths + 2 * m);
	long sum = 0;
	long max = 0;
	long curr = 0;
	for (long i = 0; i < 2 * m - 1; i++) {
		curr = curr - paths[i].second;
		for (long j = paths[i].first; j < paths[i + 1].first; j++) {
			sums[curr] += A[j];
		}
		if (paths[i].second == 1) {
			sums[curr] -= A[paths[i].first];
		}
		if (paths[i + 1].second == 1) {
			sums[curr] += A[paths[i + 1].first];
		}

		if (curr > max) {
			max = curr;
		}
	}
	/*int cnt = 0;
	int last = paths[2 * m - 1].first;
	for (long i = 0; i < 2 * m; i++) {
		if (paths[i].first == last) {
			cnt++;
		}
	}
	if (max < cnt) {
		max = cnt;
	}*/
	//sums[cnt] = A[paths[2*m-1].first];
	while (k != 0) {
		if (k > sums[max]) {
			result -= sums[max]*max;
			k = k - sums[max];
		}
		else {
			result -= k * max;
			k = 0;
		}
		max--;
	}
	cout << result;
}