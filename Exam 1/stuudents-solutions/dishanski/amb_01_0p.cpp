#include <iostream>

#include <vector>

unsigned long long N = 0;
unsigned long long K = 0;
unsigned long long C = 0;

std::vector<unsigned long long> arr;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N >> K;

    for (unsigned long long i = 0; i < N - 1; ++i) {
        std::cin >> C;
        arr.push_back(C);
    }
    
    return 0;
}