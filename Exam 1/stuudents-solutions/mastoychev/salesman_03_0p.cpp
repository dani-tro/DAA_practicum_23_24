#include <iostream>>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 100;

double prices[MAX_SIZE];

double weights[MAX_SIZE];

double bought[MAX_SIZE];

int main()
{	
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> weights[i];
		cin >> prices[i];
	}
	double sum = 0;
	double remaining = m;
	int max;
	while (true) {
		max = 0;
		for (int i = 1; i < n; i++) {
			if (prices[max] < prices[i]) {
				max = i;
			}
		}
		if (prices[max] == 0) {
			break;
		}
		if (remaining > weights[max]) {
			sum += weights[max] * prices[max];
			remaining -= weights[max];
			bought[max] = weights[max];
			prices[max] = 0;
		}
		else {
			sum += remaining * prices[max];
			bought[max] = remaining;
			break;
		}
	}
	cout << fixed << setprecision(2) << sum << endl;

	for (int i = 0; i < n; i++) {
		if (bought[i] == 0) {
			continue;
		}
		cout << fixed << setprecision(3) << bought[i] << endl;
	}
}