#include <iostream>

using namespace std;

int arr[100000];
int ks[1000];
int n, k;

int rec(int a, int b) {
	int res = arr[a] + arr[b];
	bool f = false;
	for(int i = 0; i < k; ++i) {
		if(ks[i] <b - a) {
			res = ::max(res, arr[a] + rec(a + ks[i], b));
			res = ::max(res, arr[b] + rec(a, b - ks[i]));
			f = true;
		}
	}
	return res;
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for(int i = 0; i < k;++ i) {
		cin >> ks[i];
	}

	cout << rec(0, n-1);
}
