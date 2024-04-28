#include <bits/stdc++.h>
using namespace std;

struct product {
	double price, quantity;
	int ind;
	bool operator<(const product& other) {
		return ind < other.ind;
	}
};

constexpr int MAX = 107;
int N;
double M;
product herbs[MAX]; // (price, quantity)
vector<product> res;
double profit;

bool cmp(const product& a, const product& b) {
	return a.price > b.price;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> herbs[i].quantity >> herbs[i].price;
		herbs[i].ind = i;
	}
	
	sort(herbs, herbs + N, cmp);

	for (int i = 0; i < N; i++) {
		double diff = M - herbs[i].quantity;
		if (diff > 0) {
			res.push_back({ herbs[i].price, herbs[i].quantity, herbs[i].ind });
			profit += herbs[i].quantity * herbs[i].price;
		}
		else {
			res.push_back({ herbs[i].price, M, herbs[i].ind});
			profit += M * herbs[i].price;

			break;
		}

		M -= herbs[i].quantity;
	}

	cout << fixed << setprecision(2) << profit << endl;

	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) {
		cout << fixed << setprecision(3) << res[i].quantity << endl;
	}
}