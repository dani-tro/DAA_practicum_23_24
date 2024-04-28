#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long n, k;
	long s;
	std::cin >> n >> k;
	long*arr = new long[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i] < arr[j]) {
				s = arr[j];
				arr[j] = arr[i];
				arr[i] = s;
			}
		}
	}

	long l = 0;
	long r = n - 1;
	while (l < r) {
		if (arr[r] - arr[l] <= k) {
			std::cout<< r - l + 1<<std::endl;
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
	std::cout << 0<<std::endl;
}