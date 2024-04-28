#include <iostream>

#include <vector>

#include <algorithm>

unsigned long long N = 0;
unsigned long long K = 0;
unsigned long long A = 0;

std::vector<unsigned long long> arr;

// std::cout << "Indices are: " << left << ' ' << right << std::endl;

/* unsigned long long findNumber() {
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

    
    return right - left + 1;
} */

unsigned long long findNumber() {
    unsigned long long maxNumbers   = 0;
    unsigned long long currentSize  = 0; 

    unsigned long long currentLeft  = 0;
    unsigned long long currentRight = 0;

    while (currentRight < N) {
        /* std::cout << "Pointers are: " << currentLeft << ' ' << currentRight << std::endl;
        std::cout << "Max and current are: " << maxNumbers << ' ' << currentSize << std::endl;
        std::cout << std::endl; */

        if (arr[currentRight] - arr[currentLeft] <= K) {
            currentRight += 1;
            currentSize += 1;

            maxNumbers = std::max(maxNumbers, currentSize);
        } else {
            currentLeft += 1;
            currentSize -= 1;
            maxNumbers = std::max(maxNumbers, currentSize);
        }
    }

    return maxNumbers;
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
