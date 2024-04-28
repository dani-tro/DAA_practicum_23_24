#include <iostream>
#include <vector>
#include <algorithm>

int n, k;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> k;
    std::vector<long long> atoms(n);
    for (auto &x : atoms) std::cin >> x;

    std::sort(atoms.begin(), atoms.end());

    // for (auto &x : atoms) std::cout << x << ' ';
    // std::cout << std::endl;

    long long count = 0;
    for (int i = 0; i < n; i++) {
        if (atoms[n - 1] - atoms[i] <= k) count++;
    }

    std::cout << count << std::endl;

    return 0;
}
