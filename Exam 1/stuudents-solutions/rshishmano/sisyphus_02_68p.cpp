#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include<vector>
#include<algorithm>
#include <functional>
#include <array>
#include<math.h>

int maxindex(int* ptr, int lenght) {
	int maxind = 0;
	for (int i = 0; i < lenght; i++) {
		if (ptr[i] > ptr[maxind]) {
			maxind = i;
		}
	}
	return maxind;
}
bool nullsum(int* ptr, int lenght) {
	for (int i = 0; i < lenght; i++) {
		if (ptr[i] > 0) return 0;
	}
	return 1;
}

const int M_max = 100000;
const int N_max = 100000;

using namespace std;
long  n,m, k;
int path[N_max] = { 0 };
int arr[2][M_max];
int col[N_max];
int r, indexrus;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cin >> m;
	cin >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> path[i];
		
	}
	for (int i = 0; i < m ; i++) {
		cin >> arr[0][i];
		cin >> arr[1][i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = arr[0][i] - 1; j < arr[1][i]; j++) {
			col[j] ++;
		}
	}
	/*std::cout << "\n ";
	for (int i = 0; i < n; i++) {
		std::cout <<  col[i] << " " ;
	}
	std::cout << "\n";
	*/
	while (k > 0 && !nullsum(col, n)){
		indexrus = maxindex(col, n);
		//std::cout << "removing from" << indexrus + 1 << "\n";
		while (k > 0 && path[indexrus] > 0) {
			path[indexrus]--;
			k--;
		}
		col[indexrus] = 0;
	}

	/*for (int i = 0; i < n; i++) {
		std::cout << path[i] << " ";
	}
	std::cout << "\n";
	*/
	long long travel = 0;
	for (int i = 0; i < m; i++) {
		for (int j = arr[0][i] - 1; j < arr[1][i]; j++) {
			travel += path[j];
		}
	}
	std::cout << travel;
}