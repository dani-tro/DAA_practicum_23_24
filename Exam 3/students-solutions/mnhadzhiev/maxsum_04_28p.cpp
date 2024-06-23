#include <iostream>
#include <vector>

int maxsum(int* numbers, int n, int* moves, int m) {
    int start = 0, end = n - 1;
    if (n == 1) return numbers[0];
    if (n == 2) return numbers[0] + numbers[1];

    int sum = numbers[start] + numbers[end];
    bool keep_going = true;
    while (keep_going) {
        int max_start = -10001;
        int start_idx = end;
        int max_end = -10001;
        int end_idx = 0;
        for (int i = 0; i < m; i++) {
            int step = start + moves[i];
            if (step < end && numbers[step] >= max_start && step <= start_idx) {
                max_start = numbers[step];
                start_idx = step;
            }
            if (step > end) {
                keep_going = false;
            }
        }
        for (int i = 0; i < m; i++) {
            int step = end - moves[i];
            if (step > start && numbers[step] > max_end && step >= end_idx) {
                max_end = numbers[step];
                end_idx = step;
            }
            if (step > start ) {
                keep_going = true;
            }
        }
        if (max_start >= max_end && sum + max_start > sum) {
            start = start_idx;
            sum += max_start;
        }
        else if (max_start <= max_end && sum + max_end > sum) {
            end = end_idx;
            sum += max_end;
        }
        start = start_idx;
    }
    return sum;
}

int main()
{
    int n, allowed_moves;
    std::cin >> n;
    std::cin >> allowed_moves;
    int* nums = new int[n];
    int* allowed = new int[allowed_moves];
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }
    for (int i = 0; i < allowed_moves; ++i) {
        std::cin >> allowed[i];
    }

    std::cout << maxsum(nums, n, allowed, allowed_moves);

    delete[] allowed;
    delete[] nums;
}