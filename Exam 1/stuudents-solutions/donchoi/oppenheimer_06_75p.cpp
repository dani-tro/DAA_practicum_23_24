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

    long long i = 0, j = 0;
    long long maxSize = 0;
    long long currCount = 0;

    while (j != n - 1 && i != n - 1) {
        if (atoms[j] - atoms[i] > k) {
            if (maxSize < currCount) {
                maxSize = currCount;
            }
            // std::cout << atoms[i] << ' ' << atoms[j] << ' ' << currCount << ' ' << maxSize << std::endl;
            currCount--;
            i++;
        } else {
            currCount++;
            // std::cout << atoms[i] << ' ' << atoms[j] << ' ' << currCount << ' ' << maxSize << std::endl;
            j++;
        }
    }

    currCount++;
    if (maxSize < currCount) {
        maxSize = currCount;
    }
    std::cout << maxSize << std::endl;

    return 0;
}
