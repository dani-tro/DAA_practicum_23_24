#include <iostream>
#include <algorithm>
#include <vector>

const int MAX_N = 1e5;
const int MAX = 1e9;

int main() {

    int n, k;
    int ans = 0;

    //  Input data
    std::cin >> n >> k;
    std::vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    // TODO Validation

    std::sort(a.begin(), a.end());

    // Sliding window with binary search modification
    // O(N*logN) average tc

    int l = 0;
    int h = n - 1;

    while (l <= h) {
        int currDiff = a[h] - a[l];

        if (currDiff <= k) {
            ++ans;
            ++l;
        } else {
            ++l;
        }
    }

    std::cout << ans;
    return 0;
}
