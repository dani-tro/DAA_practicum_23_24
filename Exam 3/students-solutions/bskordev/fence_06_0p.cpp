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

    long long s;
    std::cin >> s;

    long long result = 0;

    std::vector<std::vector<long long>> currColumn(s + 1, std::vector<long long>(s + 1, 0));
    std::vector<std::vector<long long>> nextColumn(s + 1, std::vector<long long>(s + 1, 0));

    for (long long i = 1; i <= s; i++) {
        currColumn[i][i] = 1;
    }
    result += currColumn[s][s];

    for (long long c = 2; c <= s; c++) {
        
        for (int i = 1; i <= s; i++) {
            for (int j = 1; j < i; j++) {
                nextColumn[i][j] = 0;
                for (int d = 1; d < j; d++) {
                    nextColumn[i][j] = mod(nextColumn[i][j] + currColumn[i - j][d]);
                }

                for (int d = j + 1; d < i; d++) {
                    nextColumn[i][j] = mod(nextColumn[i][j] + currColumn[i - j][d]);
                }
            }
        }


        for (long long i = 1; i <= s; i++) {
            result = mod(result + nextColumn[s][i]);
        }
        currColumn = nextColumn;
    }

    std::cout << result << std::endl;

    return 0;
}