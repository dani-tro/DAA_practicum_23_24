#include <iostream>
#include <vector>

int sums(int n, int a, int b, int* nums, bool* seen) {
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int prev = nums[i];
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            if (prev >= a && prev <= b && !seen[prev - a]) {
                result++;
                seen[prev - a] = true;
            }
            else if (prev > b && j > 0) {
                prev -= nums[j - 1];
            }
            prev += nums[j];
        }
    }
    return result;
}

int main()
{
    int n, a, b;
    std::cin >> n;
    std::cin >> a;
    std::cin >> b;
    int* nums = new int[n];
    bool* seen = new bool[b - a + 1];
    for (int i = 0; i < b - a + 1; ++i) {
        seen[i] = false;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::cout << sums(n, a, b, nums, seen);

    delete[] seen;
    delete[] nums;
}