#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include<vector>
#include<algorithm>
#include <functional>
#include <array>


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
	for (int i = 0; i < n; i++) {
		std::cin >> r;
		arr.push_back(r);
	}
	std::sort(arr.begin(), arr.end());
	for (int i = n; i > 0; i--) {
		for (int j = n-1 ; j >= 0; j--) {
			if (j - i + 1 < 0) break;
			if (arr[j] - arr[j - i + 1] <= k) {
				std::cout << i;
				return 0;
			}
		}
	}
}