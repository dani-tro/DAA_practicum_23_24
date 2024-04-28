#include <iostream>
#include <vector>
#include <algorithm>

long n, k;

void updateTelevisions(std::vector<long long>& tvs, long l, long r) {
    if (k == 0) return;
    long mid = (l + r) / 2;
    tvs[mid] = 1;
    k--;
    updateTelevisions(tvs, 0, mid);
    updateTelevisions(tvs, mid + 1, n - 2);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> k;
    std::vector<long long> distances(n - 1);
    for (auto &x : distances) std::cin >> x;

    std::vector<long long> tvs(n - 1);
    updateTelevisions(tvs, 0, n - 1);

    long long maxDist = 0;
    long long currDist = 1;
    for (int i = 0; i < n - 1; i++) {
        if (maxDist <= currDist) {
            maxDist = currDist;
        }
        if (tvs[i] == 0) {
            currDist += distances[i];
        }
    }

    if (maxDist <= currDist) {
        maxDist = currDist;
        currDist = 0;
    }

    std::cout << maxDist << std::endl;

    return 0;
}
