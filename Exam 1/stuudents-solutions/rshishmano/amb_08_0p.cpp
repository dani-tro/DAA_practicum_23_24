#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include<vector>
#include<algorithm>
#include <functional>
#include <array>
#include<math.h>

int cell(double a) {
	if (a - int(a) > 0) {
		return a + 1;
	}
	return a;
}


using namespace std;
long  n, k;
std::vector<int> arr;
int r;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cin >> k;
	for (int i = 0; i < n - 1; i++) {
		std::cin >> r;
		arr.push_back(r);
	}
	if (k == 1) {
		std::cout << pow(2, n - 2);
		return 0;
	}
	if(k % 2 == 0) {
		std::cout << pow(2, n - k) - 1;
	}
	if (k % 2 == 1) {
		std::cout << pow(2, n - k - 1);
	}

}