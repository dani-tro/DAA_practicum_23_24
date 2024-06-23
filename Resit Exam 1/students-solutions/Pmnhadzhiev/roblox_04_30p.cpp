#include <iostream>

unsigned long long get_sub_array_total(unsigned long l, unsigned long r, unsigned long long* nums) {
    unsigned long long sum = 0;
    for (long i = l; i < r; ++i) {
        for (long j = i + 1; j <= r; ++j) {
            sum += nums[i] * nums[j];
        }
    }
    return sum;
}

int main()
{
    unsigned long n, k;
    std::cin >> n;
    std::cin >> k;
    unsigned long long* boxers = new unsigned long long[n];
    for (long i = 0; i < n; ++i) {
        std::cin >> boxers[i];
    }
    if (n <= 1) std::cout << 0;
    unsigned long left = 0, right = 1;
    int res = 0;
    unsigned long long sum = 0;
    while (left <= right && right < n) {
        sum = get_sub_array_total(left, right, boxers);
        if (sum < k) {
            right++;
        }
        else {
            res += n - right;
            left++;
            right = left + 1;
        }
    }
    std::cout << res;
    delete[] boxers;
}

