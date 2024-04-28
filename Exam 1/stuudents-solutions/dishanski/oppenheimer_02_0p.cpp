#include <iostream>

#include <vector>

#include <algorithm>

unsigned long long N = 0;
unsigned long long K = 0;
unsigned long long A = 0;

std::vector<unsigned long long> arr;

unsigned long long findNumber() {
    std::size_t left    =   0;
    std::size_t right   =   arr.size() - 1;

    while (arr[right] - arr[left] > K) {
        unsigned long long dist1 = arr[left + 1] - arr[left];
        unsigned long long dist2 = arr[right] - arr[right - 1];

        if (dist1 > dist2) {
            left = left + 1;
        } else {
            right = right - 1;
        }
    }

    // std::cout << "Indices are: " << left << ' ' << right << std::endl;
    return right - left + 1;

    /* while (arr[right] - arr[left] > K) {

    } */

    /* for (std::size_t i = 0; i < arr.size(); ++i) {
        if (arr[right] - arr[i] <= K) {
            return N - i;
        }
    } */
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N >> K;

    for (unsigned long long i = 0; i < N; ++i) {
        std::cin >> A;
        arr.push_back(A);
    }

    std::sort(arr.begin(), arr.end());

    // 5 9 3 1 2 7 8 9 5 8
    // 1 2 3 5 5 7 8 8 9 9

    // 5 9 7 8 9 5 8

    std::cout << findNumber() << std::endl;

    return 0;
}
