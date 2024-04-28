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
	for (int i = 0; i < n - 1; i++) {
		std::cin >> r;
		arr.push_back(r);
	}
	//std::sort(arr.begin(), arr.end());
	long dis = (n - 1) * arr[n-2];
	std::cout << floor(dis / (2 * k));
}