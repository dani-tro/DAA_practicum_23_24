#include <iostream>

int get_sub_array_total(int l, int r, int* nums) {
    int sum = 0;
    for (int i = l; i < r - 1; ++i) {
        for (int j = l + 1; j < r; ++j) {
            sum += nums[i] * nums[j];
        }
    }
    return sum;
}

int main()
{
    int n, k;
    std::cin >> n;
    std::cin >> k;
    int* boxers = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> boxers[i];
    }
    if (n <= 1) std::cout << 0;
    int left = 0, right = 1;
    int res = 0;
    int sum = 0;
    while (left < right && right < n) {
        sum = get_sub_array_total(left, right, boxers);
        if (sum < k) {
            right++;
        }
        else {
            res += 1 + n - right;
            left++;
            right = left + 1;
        }
    }
    std::cout << res;
    delete[] boxers;
}