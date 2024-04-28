#include <iostream>
#include <vector>
#include <iomanip>

double ternarySearch(std::vector<double> const& a, std::vector<double> const& b, double m,
	std::vector<double>& c, long long index) {
	long long n = a.size();

	double l = 0, h = std::min(a[index], m);
	double m1, m2, c1, c2;
	for (int i = 0; i < 200; i++) {
		m1 = l + (h - l) * (1.0 / 3);
		m2 = l + (h - l) * (2.0 / 3);

		c1 = m1 * b[index];
		c2 = m2 * b[index];

		if (index < n - 1) {
			c1 += ternarySearch(a, b, m - m1, c, index + 1);
			c2 += ternarySearch(a, b, m - m2, c, index + 1);
		}

		if (c1 > c2) {
			h = m2;
		}
		else {
			l = m1;
		}
	}

	c[index] = h;

	if (index == n - 1) {
		return c[index] * b[index];
	}

	return c[index] * b[index] + ternarySearch(a, b, m - l, c, index + 1);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	double m;
	long long n;
	std::cin >> m >> n;

	std::vector<double> a;
	std::vector<double> b;
	for (int i = 0; i < n; i++) {
		double ai, bi;
		std::cin >> ai >> bi;
		
		a.push_back(ai);
		b.push_back(bi);
	}

	std::vector<double> c(n, 0);

	std::cout << std::fixed << std::setprecision(3) << ternarySearch(a, b, m, c, 0) << std::endl;

	for (double& s : c) {
		std::cout << std::fixed << std::setprecision(2) << s << std::endl;
	}

	return 0;
}