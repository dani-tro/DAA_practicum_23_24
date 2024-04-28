#include <climits>
#include <iostream>
#include <vector>

int n, k;
std::vector<long long> atoms(n);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> k;
    for (auto &x : atoms) std::cin >> x;

    std::sort(atoms.begin(), atoms.end());

    long long currMin = LONG_LONG_MAX;
    long long currMax = 0;
    long long currLength = 0;
    for (int i = 0; i < n; i++) {
        if (atoms[i] <= currMin) {
            currMin = atoms[i];
        }
        if (atoms[i] >= currMax) {
            currMax = atoms[i];
        }
        if (currMax - currMin > k) {
            currLength = 0;
            currMin = LONG_LONG_MAX;
            currMax = 0;
        } else {
            currLength++;
        }
    }

    std::cout << currLength << std::endl;

    return 0;
}
