#include <iostream>
#include <vector>

long long MOD = 1000000007;

long long mod(long long x) {
    return (x % MOD + MOD) % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int s;
    std::cin >> s;

    std::vector<std::vector<std::vector<long long>>>
        l(s + 1, std::vector<std::vector<long long>>(s + 1, std::vector<long long>(s + 1, 0)));

    std::vector<std::vector<std::vector<long long>>>
        h(s + 1, std::vector<std::vector<long long>>(s + 1, std::vector<long long>(s + 1, 0)));

    for (int i = 1; i <= s; i++) {
        l[i][1][i] = 1;
        h[i][1][i] = 1;
    }

    long long result = 0;

    std::cout << result << std::endl;

    return 0;
}