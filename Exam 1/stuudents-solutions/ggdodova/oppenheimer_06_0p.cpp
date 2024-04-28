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
    long long answer=N;

    long long l=0;
    long long r=N-1;
    long long minimumK=numbers[l];
    long long maximumK=numbers[r];
    while (l <= r + 1) {
        if ((maximumK - minimumK) > K) {
            answer--;
            l++;
            minimumK = numbers[l];
        } else{
            r--;
            maximumK = numbers[r];
        }

    }
    std::cout << answer;

    return 0;
}
