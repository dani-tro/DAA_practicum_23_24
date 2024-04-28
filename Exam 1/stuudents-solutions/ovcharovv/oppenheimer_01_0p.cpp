#include <iostream>
#include <algorithm>

int main() {
	int n, k;
	int s;
	std::cin >> n >> k;
	int *arr = new int [n];
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

	int l = 0;
	int r = n - 1;
	while (l <= r) {
		if (arr[r] - arr[l] <= k) {
			std::cout<< r - l+1;
			break;
		}
		else {
			if (arr[r] - arr[l + 1] <= k) {
				std::cout<< r - l;
				break;
			}
			else {
				l++;
				continue;
			}
		}
	}
}