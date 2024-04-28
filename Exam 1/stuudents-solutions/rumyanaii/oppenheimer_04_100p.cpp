#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long a[100100];
long long k;

bool canPickM(long long m) {
	for (int i = 0; i <= n - m; i++) {
		if (a[i + m - 1] - a[i] <= k) {
			return true;
		}
	}
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);

	int l = 0;
	int r = 1000000000;
	int m;
	while (l <= r) {
		m = (l + r) / 2;
		//cout << l << " " << m << " " << r << endl;
		if (canPickM(m) && !canPickM(m + 1)) {
			break;
		}
		if (canPickM(m)) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	//canPickM(5);
	cout << m << endl;

	return 0;
}

/*
bool canPickM(long long m) {
	long long mini = 0;
	long long maxi = n-1;

	while (mini < maxi)
	{
		if (a[maxi] - a[mini] > m) {
			if (a[maxi] - a[mini + 1] < a[maxi - 1] - a[mini]) {
				mini++;
			}
			else {
				maxi--;
			}
		}
		else {
			return true;
		}
	}
	return false;
}
*/
