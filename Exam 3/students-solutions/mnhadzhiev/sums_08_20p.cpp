#include <iostream>
#include <vector>
int sums() {
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
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int prev = nums[i];
        if (prev <= b) {
            for (int j = i; j < n; ++j) {
                if (prev >= a && prev <= b && !seen[prev - a]) {
                    result++;
                    seen[prev - a] = true;
                }
                else if (prev > b && j > i) {
                    prev -= nums[j - 1];
                }
                if (j > i) {
                    prev += nums[j];
                }
            }
        }
    }

    delete[] seen;
    delete[] nums;
    return result;
}

int main()
{
    std::cout << sums() << '\n';

}