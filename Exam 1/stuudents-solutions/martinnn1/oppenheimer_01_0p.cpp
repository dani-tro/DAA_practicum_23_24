#include <iostream>
#include <cstdio>
#include <iomanip>
#include <math.h>
#include <climits>

void Merge(long* arr, int low, int mid, int high);
void MergeSort(long* arr, int low, int high);

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie();
	std::cout.tie();

	int n, k;
	std::cin >> n >> k;

	long* criticalLevels = new long[n];
	for (int i = 0; i < n; i++) {
		std::cin >> criticalLevels[i];
	}

	MergeSort(criticalLevels, 0, n - 1);

	for (int i = 0; i < n; i++) {
		std::cout << criticalLevels[i] << " ";
	}
	std::cout << std::endl;

	int maxCount = 0;
	long currNumber;
	for (int i = n - 1; i >= 0; --i) {
		int count = 1;
		currNumber = criticalLevels[i];

		for (int j = i - 1; j >= 0; --j) {
			long currInnerNumber = criticalLevels[j];

			if (currNumber - currInnerNumber <= k && currInnerNumber - currNumber <= k) {
				++count;
			}
			else {
				break;
			}
		}

		if (count > maxCount) {
			maxCount = count;
		}
	}

	std::cout << maxCount;

	return 0;
}

void MergeSort(long* arr, int low, int high) {
	if (low >= high) {
		return;
	}

	int mid = low + (high - low) / 2;
	MergeSort(arr, low, mid);
	MergeSort(arr, mid + 1, high);
	Merge(arr, low, mid, high);
}

void Merge(long* arr, int low, int mid, int high) {
	int sizeLeft = mid - low + 1;
	int sizeRight = high - mid;

	long* arrLeft = new long[sizeLeft];
	long* arrRight = new long[sizeRight];

	for (int i = 0; i < sizeLeft; i++) {
		arrLeft[i] = arr[low + i];
	}

	for (int i = 0; i < sizeRight; i++) {
		arrRight[i] = arr[mid + 1 + i];
	}

	int indexLeft = 0;
	int indexRight = 0;
	int arrIndex = low;
	while (indexLeft < sizeLeft && indexRight < sizeRight) {
		if (arrLeft[indexLeft] <= arrRight[indexRight]) {
			arr[arrIndex] = arrLeft[indexLeft];
			++indexLeft;
			++arrIndex;
		}
		else {
			arr[arrIndex] = arrRight[indexRight];
			++indexRight;
			++arrIndex;
		}
	}

	while (indexLeft < sizeLeft) {
		arr[arrIndex] = arrLeft[indexLeft];
		++indexLeft;
		++arrIndex;
	}

	while (indexRight < sizeRight) {
		arr[arrIndex] = arrRight[indexRight];
		++indexRight;
		++arrIndex;
	}

	delete[] arrLeft;
	delete[] arrRight;
}
