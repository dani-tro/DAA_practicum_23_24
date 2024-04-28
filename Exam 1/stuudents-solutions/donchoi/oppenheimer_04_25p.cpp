#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n, k;
    std::cin >> n >> k;
    std::vector<long long> atoms(n);
    for (auto &x : atoms) std::cin >> x;

    std::sort(atoms.begin(), atoms.end());

    // for (auto &x : atoms) std::cout << x << ' ';
    // std::cout << std::endl;

    long long count = 1;
    long long i = 0, j = 1;
    std::vector<long long> allCounts;

    while (i != j && j != n - 1 && i != n - 1) {
        if (atoms[j] - atoms[i] > k) {
            allCounts.push_back(count);
            count--;
            i++;
        } else {
            count++;
            j++;
        }
    }

    count++;
    allCounts.push_back(count);
    long long currMax = 0;
    for (auto &x : allCounts) {
        // std::cout << x << ' ';
        if (x > currMax) currMax = x;
    }

    std::cout << currMax << std::endl;

    return 0;
}
