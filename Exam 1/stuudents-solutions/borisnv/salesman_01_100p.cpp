#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>

using namespace std;

double m;
int n;

struct spice {
	double price;
	double amount;
	int i;
};

bool cmp(const spice a, const spice b) {
	return a.price > b.price;
}

spice a[101];
double amounts[101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
	
	cin >> m >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i].amount >> a[i].price;
		a[i].i = i;;
	}

	sort(a, a + n, cmp);
	
	double sum = 0;
	int i = 0;
	while(i < n) {
		if(m >= a[i].amount) {
			m -= a[i].amount;
			sum += a[i].amount * a[i].price;
			amounts[a[i].i] = a[i].amount;
		} else {
			sum += m * a[i].price;
			amounts[a[i].i] = m;
			m = 0;
		}
		++i;
	}
	cout << fixed << setprecision(2) << sum << '\n';
	for(int i = 0; i < n; ++i) {
		cout << fixed << setprecision(3) << amounts[i] << '\n';
	}
	return 0;
}
