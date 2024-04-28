#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

double capasity;
pair<double, pair<long long, double>>  a[100100];
pair<long long, double> p[100100];
long long n;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> capasity >> n;
	double tmp;
	for (int i = 0; i < n; i++) {
		cin >> a[i].second.second;
		cin >> a[i].first;
		a[i].second.first = i;
	}
	sort(a, a + n);
	double curLoad = 0;
	double profit = 0;
	int i = n-1;
	int j = 0;
	while (curLoad < capasity && i >= 0) {
		if (curLoad + a[i].second.second < capasity) {
			profit += a[i].second.second * a[i].first;
			curLoad += a[i].second.second;
			p[j] = a[i].second;
		}
		else {
			p[j].first = a[i].second.first;
			p[j].second = (capasity - curLoad);

			profit += (capasity - curLoad) * a[i].first;
			curLoad += capasity - curLoad;
		}
		i--;
		j++;
	}

	cout << fixed << setprecision(2) << profit << endl;
	sort(p, p + n);
	for (int i = 0; i < j; i++) {
		cout << fixed << setprecision(3) << p[i].second << endl;
	}
	return 0;
}

