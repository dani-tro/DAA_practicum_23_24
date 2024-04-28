#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX = 100'007;
int N, K;
long long arr[MAX];
bool tvs[MAX];
long long maxDist;

void getMaxDist(int l, int r, int ind) {
	if (tvs[ind] == 1) return;
	maxDist = max(maxDist, arr[ind] - arr[l]);
	maxDist = max(maxDist, arr[r] - arr[ind]);
}

void f(int l, int r) {
	if (K <= 0) {
		return;
	}
	if (l < r) {
		int mid = (l + r) / 2;
		//getMaxDist(l, r, mid);
		tvs[mid] = 1;
		K--;
		f(mid + 1, r);
		f(l, mid - 1);
		//if ((l + r) % 2 == 0) {
		//	getMaxDist(l, r, mid + 1);
		//}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	long long d;
	for (int i = 1; i < N; i++) {
		cin >> d;
		arr[i] = arr[i - 1] + d;
	}

	f(0, N - 1);

	int lastX = 0;
	for (int i = 0; i < N; i++) {
		if (tvs[i] == 1) {
			int mid = (lastX + i) / 2;
			getMaxDist(lastX, i, mid);
			if ((lastX + i) % 2 == 0) getMaxDist(lastX, i, mid + 1);
			lastX = i;
		}
	}

	cout << maxDist << endl;
}