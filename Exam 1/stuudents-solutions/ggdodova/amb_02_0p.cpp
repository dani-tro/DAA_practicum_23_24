#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

int main() {
int N, K;
std::cin>>N>>K;
std::vector<int> nums(N);
    for (int i = 0; i < N-1; ++i) {
        std::cin>>nums[i];
    }
    std::sort(nums.begin(), nums.end());
    long long l = 0;
    long long r = N- 1;
    long long answer = 0;
    long long sumLeft=0;
    long long sumRight=0;
    while (l <= r + 1) {
        if ((sumRight- sumLeft) >= K) {
            answer++;
            //answer = std::max(answer, l + (K - 1 - r));
        }
        if ((sumRight- sumLeft) <=K) {
            sumRight += nums[r];
            r--;

        } else {
            sumLeft += nums[l];
            l++;
        }
    }
    std::cout << answer << "\n";

    return 0;
}
