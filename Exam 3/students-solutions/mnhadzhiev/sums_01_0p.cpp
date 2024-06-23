#include <iostream>
#include <vector>

int sums(int n, int a, int b, int* nums, bool* seen) {
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int prev = nums[i];
        int j = i + 1;
        if (j >= n) {
            if (!seen[prev - a + 1] && prev >= a && prev <= b) result++;
            break;
        }
        while (prev <= b) {
            if (prev >= a && !seen[prev - a + 1]) {
                result++;
                seen[prev - a + 1] = true;
            }
            prev += nums[j++];
            
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
    std::cout << "Hello World!\n";
}