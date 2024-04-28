#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include<vector>
#include<algorithm>
#include <functional>
#include <array>
//#include <bits/stdc++.h>

using namespace std;
long  n, k;
int atoms = 0;
std::vector<int> arr;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++) {
		int r;
		std::cin >> r;
		arr.push_back(r);
	}
	std::sort(arr.begin(), arr.end());
	int i = 0;
	int j = n - 1;
	for (auto a : arr) {
		std::cout << a << " ";
	}
	std::cout << '\n';
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < n; j++) {
			if (i + j > n - 1) break;
			if (arr[j + i - 1] - arr[j] <= k) {
				atoms = i;
				std::cout << atoms + 1;
				return 0;
			}
		}
	}
	std::cout << atoms+1;
	return 0;
}