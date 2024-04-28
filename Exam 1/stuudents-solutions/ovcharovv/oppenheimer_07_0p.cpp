#include <iostream>
#include <algorithm>

int main() {
	long n, k;
	long s;
	std::cin >> n >> k;
	long*arr = new long[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	std::sort(arr, arr + n);
	long l = 0;
	long r = n - 1;
	while (l < r) {
		if (arr[r] - arr[l] <= k) {
			std::cout<<r-l+1<<std::endl;
			return 0;
		}
		else {
			if(arr[r]-arr[l+1] < arr[r-1]-arr[l]){
				l++;
			}
			else {
				r--;
			}
		}
	}
	std::cout<<0<<std::endl;
}