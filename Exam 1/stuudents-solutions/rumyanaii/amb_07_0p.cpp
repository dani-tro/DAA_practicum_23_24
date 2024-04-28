#include <iostream>
#include <algorithm>

using namespace std;

long long n, k;
long long d[100100];

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


bool greedyTV(int maxd) {
	long long curd = 0;
	long long lastTV = 0;
	int tvs = k;
	for (int i = 0; i < n - 1; i++) {

		if (curd + d[i] > maxd && lastTV > maxd) {
			curd = 0;
			lastTV = 0;
			tvs--;
		}
		else {
			curd += d[i];
		}
		if (tvs < 0) {
			return false;
		}
	}
	return true;
}


*/

bool greedyTV(long long maxd) {
	long long curd = 0;
	long long lastTV = 0;
	long long tvs = k;
	for (long long i = 0; i <= n - 1; i++) {
		if (d[i+1] - lastTV > maxd) {
			lastTV = d[i];
			tvs--;
		}
		if (tvs < 0) {
			return false;
		}
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	d[0] = 0;
	for (long long i = 1; i < n; i++) {
		cin >> d[i];
		d[i] += d[i - 1];
	}
	d[n] = d[n-1];
	long long l = 1;
	long long r = 1000000000;
	long long m;
	while (l < r) {
		m = (l + r) / 2; 
		//cout << l << " " << m << " " << r << endl;
		if (greedyTV(m) && !greedyTV(m - 1)) {
			break;
		}
		if (greedyTV(m)) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	//greedyTV(3);
	cout << m << endl;

	return 0;
}
