#include <iostream>

const int MAX=100001;
long long sumLeft;
long long sumRight;

void solve() {
    long long N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        long long K;
        long long arr[MAX];
        std::cin >> K;
        for (int j = 0; j < K; ++j) {
            std::cin >> arr[j];
        }
        long long l = 0;
        long long r = K - 1;
        long long answer = 0;
        while (l <= r + 1) {
            if (sumLeft == sumRight) {
                answer = std::max(answer, l + (K - 1 - r));
            }
            if (sumLeft >= sumRight) {
                sumRight += arr[r];
                r--;

            } else {
                sumLeft += arr[l];
                l++;
            }
        }
        std::cout << answer << "\n";
    }

}
