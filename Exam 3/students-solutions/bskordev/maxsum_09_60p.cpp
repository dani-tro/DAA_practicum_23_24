#include <iostream>
#include <vector>
#include <climits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a.push_back(x);
    }

    std::vector<int> m;
    for (int i = 0; i < k; i++) {
        int x;
        std::cin >> x;
        m.push_back(x);
    }

    std::vector<int> l(n, INT_MIN / 2);
    std::vector<bool> lVisited(n, false);
    l[0] = a[0];
    lVisited[0] = true;
    for (int i = 1; i < n - 1; i++) {
        for (int& move : m) {
            if (i - move >= 0 && lVisited[i - move]) {
                l[i] = std::max(l[i], l[i - move] + a[i]);
                lVisited[i - move] = true;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        l[i] = std::max(l[i], l[i - 1]);
    }

    std::vector<int> r(n, INT_MIN / 2);
    std::vector<bool> rVisited(n, false);
    r[n - 1] = a[n - 1];
    rVisited[n - 1] = true;
    for (int i = n - 2; i > 0; i--) {
        for (int& move : m) {
            if (i + move <= n - 1 && rVisited[i + move]) {
                r[i] = std::max(r[i], r[i + move] + a[i]);
                rVisited[i] = true;
            }
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        r[i] = std::max(r[i], r[i + 1]);
    }

    int result = INT_MIN / 2;;
    for (int i = 0; i < n - 1; i++) {
        result = std::max(result, l[i] + r[i + 1]);
    }

    std::cout << result << std::endl;

    return 0;
}