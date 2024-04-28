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
	while (i < j) {
		if (arr[j] - arr[i] == k) {
			atoms = j - i;
			break;
		}
		if (arr[i] + arr[j] > k) {
			j--;
		}
	}
	i = 0;
	j = n - 1;
	while (i < j) {
		if (arr[j] - arr[i] == k) {
			if (j - i > atoms) {
				atoms = j - i;
			}
			break;
		}
		if (arr[i] + arr[j] > k) {
			i++;
		}
	}
	std::cout << atoms+1;


	return 0;
}