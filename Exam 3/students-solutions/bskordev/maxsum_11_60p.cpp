#include <iostream>
#include <vector>
#include <climits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n, k;
    std::cin >> n >> k;

    std::vector<long long> a;
    for (long long i = 0; i < n; i++) {
        long long x;
        std::cin >> x;
        a.push_back(x);
    }

    std::vector<long long> m;
    for (long long i = 0; i < k; i++) {
        long long x;
        std::cin >> x;
        m.push_back(x);
    }

    std::vector<long long> l(n, LLONG_MIN / 2);
    std::vector<bool> lVisited(n, false);
    l[0] = a[0];
    lVisited[0] = true;
    for (long long i = 1; i < n - 1; i++) {
        for (long long& move : m) {
            if (i - move >= 0 && lVisited[i - move]) {
                l[i] = std::max(l[i], l[i - move] + a[i]);
                lVisited[i - move] = true;
            }
        }
    }

    for (long long i = 1; i < n; i++) {
        l[i] = std::max(l[i], l[i - 1]);
    }

    std::vector<long long> r(n, LLONG_MIN / 2);
    std::vector<bool> rVisited(n, false);
    r[n - 1] = a[n - 1];
    rVisited[n - 1] = true;
    for (long long i = n - 2; i > 0; i--) {
        for (long long& move : m) {
            if (i + move <= n - 1 && rVisited[i + move]) {
                r[i] = std::max(r[i], r[i + move] + a[i]);
                rVisited[i] = true;
            }
        }
    }

    for (long long i = n - 2; i >= 0; i--) {
        r[i] = std::max(r[i], r[i + 1]);
    }

    long long result = LLONG_MIN / 2;;
    for (long long i = 1; i < n; i++) {
        result = std::max(result, l[i - 1] + r[i]);
    }

    std::cout << result << std::endl;

    return 0;
}