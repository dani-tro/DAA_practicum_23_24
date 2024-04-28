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
    long long sumLeft=0;
    long long sumRight=0;
    while (l <= r + 1) {
        if ((sumRight- sumLeft) >= K) {
            answer++;
            answer = std::max(answer, l + (K - 1 - r));
        }
        if ((sumRight- sumLeft) <=K) {
            sumRight += numbers[r];
            r--;

        } else {
            sumLeft += numbers[l];
            l++;
        }
    }
    std::cout << answer << "\n";

    return 0;
}
