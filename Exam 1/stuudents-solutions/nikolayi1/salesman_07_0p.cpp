int getMax(pair<double, double>* arr, int n) {
	int max = -1;
	for (int i = 0; i < n; ++i) {
		if (max == -1 && a[i].first > 0) {
			max = i;
		}
		if (arr[i].second > arr[max].second && arr[i].first > 0) {
			max = i;
		}
	}

	return max;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	float m;
	int n, i;
	float q, p;
	cin >> m >> n;
	for (i = 0; i < n; ++i) {
		cin >> q >> p;
		a[i] = make_pair(q, p);
	}

	int last = -1;
	double total = 0;

	int ind = -2, last_ind = -1;
	while (m > 0 && ind != -1) {
		ind = getMax(a, n);
		if (a[ind].first < m) {
			total += a[ind].first * a[ind].second;
			m -= a[ind].first;
			a[ind].first = -a[ind].first;
		}
		else {
			total += m * a[ind].second;
			last_ind = ind;
			break;
		}
	}

	cout << fixed << setprecision(2) << total << endl;

	for (i = 0; i < n; ++i) {
		if (a[i].first <= 0 && i != last_ind) cout << fixed << setprecision(3) << -a[i].first << endl;
		else if (i == last_ind) cout << fixed << setprecision(3) << m << endl;
		else cout << "0.000" << endl;
	}

}