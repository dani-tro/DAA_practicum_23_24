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
	unsigned right = 1;
	unsigned res = 1;

	while (right < size) {
		if (arr[right] - arr[left] <= K) {
			right++;
			res++;
		}
		else {
			left++;
			res--;
		}
	}

	return res;
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