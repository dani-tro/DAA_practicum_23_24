#include <iostream>
#include <algorithm>
#include <vector>


int main() {
    //std::ios_base::sync_with_stdio(false);
    //std::cin.tie(NULL);
    long long N, K;
    std::cin>>N>>K;
    std::vector<long long> numbers(N);
    for (int i = 0; i < N; ++i) {
        std::cin>>numbers[i];
    }
    std::sort(numbers.begin(), numbers.end());
    long long l = 0;
    long long r = N- 1;
    long long answer = 0;
    long long minimumK=numbers[l];
    long long maximumK=numbers[r];
    while (l <= r + 1) {
        if ((maximumK - minimumK) <= K) {
            answer++;
            answer = std::max(answer, l + (K - 1 - r));
        }
        if ((maximumK - minimumK) >= K) {
            maximumK = numbers[r];
            r--;

        } else {
            minimumK = numbers[l];
            l++;
        }
    }
    std::cout << answer << "\n";

    return 0;
}
