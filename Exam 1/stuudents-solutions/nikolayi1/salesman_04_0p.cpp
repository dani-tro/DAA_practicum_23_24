#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAX = 105;
pair<float, float> a[MAX];

int main() {
	float m;
	int n, i;
	float q, p;
	cin >> m >> n;
	for (i = 0; i < n; ++i) {
		cin >> q >> p;
		a[i] = make_pair(q, p);
	}

	sort(a, a + n);

	int last = -1;
	float total = 0;

	for (i = 0; i < n; ++i) {
		if (a[i].first > m) {
			last = i;
			total += m * a[i].second;
			break;
		}
		else {
			total += a[i].first * a[i].second;
			m -= a[i].first;
		}
	}

	if (last == -1) last = n;

	cout << fixed << setprecision(2) << total << endl;

	for (i = 0; i < n; ++i) {
		if (i < last) cout << fixed << setprecision(3) << a[i].first << endl;
		else if (i == last) cout << fixed << setprecision(3) << m << endl;
		else cout << fixed << setprecision(3) << "0.000" << endl;
	}
}