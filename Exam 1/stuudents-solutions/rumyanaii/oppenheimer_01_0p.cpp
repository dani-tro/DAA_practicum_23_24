#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long a[100100];
long long k;

bool canPickM(long long m) {
	long long mini = 0;
	long long maxi = 0;

	while (mini <= maxi)
	{
		if (a[maxi] - a[mini] > m) {
			mini++;
			if (mini < 0) {
				return false;
			}
		}
		else  if(a[maxi] - a[mini] < m) {
			maxi++;
			if (maxi > n-1) {
				return false;
			}
		}
		else {
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
	sort(a, a + n-1);

	int l = 0; 
	int r = 1000000000;
	int m;
	while (l < r) {
		m = (l + r) / 2;
		//cout << l << " " << m << " " << r << endl;
		if (canPickM(m)) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	cout << m << endl;

	return 0;
}