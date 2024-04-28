#include<iostream>
#define MAX 100000

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void sort(int arr[], const int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[j] > arr[i]) {
				swap(arr[j], arr[i]);
			}
		}
	}
}

int findLongestWindow(int arr[], const int size, const int K) {
	unsigned left = 0;
	unsigned right = 0;
	unsigned res = 0;
	unsigned best = 0;

	while (right < size) {
		if (arr[right] - arr[left] <= K) {
			right++;
			res++;
			if (res > best) {
				best = res;
			}
		}
		else {
			left++;
			res--;
		}
	}

	return best;
}

int main() {
	unsigned N;
	unsigned K;

	scanf("%u %u\n", &N, &K);

	int arr[MAX];


	for (int i = 0; i < N; i++) {
		scanf("%i", &arr[i]);
	}

	sort(arr, N);

	printf("%i", findLongestWindow(arr, N, K));
}