#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

#define MAXN 105

int n, m, idx = 1;
double profit;

struct prod {
	double w, p;
	double id;

	bool operator<(const prod& other) const {
		if (p == other.p) return id < other.id;
		return p > other.p;
	}
};
prod a[MAXN], aOrig[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].w >> a[i].p;
		a[i].id = i;
		aOrig[i] = a[i];
	}
	sort(a + 1, a + n + 1);

	while (idx <= n && m > 0) {
		if (a[idx].w <= m) {
			profit += a[idx].p * a[idx].w;
			m -= a[idx].w;
			aOrig[(int)a[idx].id].id = a[idx].w;
		}
		else {
			profit += m * a[idx].p;
			aOrig[(int)a[idx].id].id = m;
			m = 0;
		}
		idx++;
	}
	for (idx; idx <= n; idx++)
		aOrig[(int)a[idx].id].id = 0;

	cout << fixed << setprecision(2) << profit << endl;
	
	for (int i = 1; i <=n; i++) 
		cout << fixed << setprecision(3) << aOrig[i].id << endl;
	
	return 0;
}