#include <vector>
#include <climits>
#include <iostream>

long long S = 0;
long long R = 0;

std::vector<long long> fence;

void print() {
    for (int i = 0; i < fence.size(); ++i) {
        std::cout << fence[i] << ' ';
    }

    std::cout << std::endl;
}

bool check() {
    if (fence.size() == 2) {
        return  fence.front() < fence.back() ||
                fence.front() > fence.back();
    }

    for (int i = 1; i < fence.size() - 1; ++i) {
        bool condition1 = (fence[i] < fence[i - 1] && fence[i] < fence[i + 1]);
        bool condition2 = (fence[i] > fence[i - 1] && fence[i] > fence[i + 1]);

        if (!(condition1 || condition2)) {
            return false;
        }
    }

    return true;
}

void calculate(int remaining) {
    if (remaining == 0) {
        if (check()) {
            // print();
            R %= 1'000'000'007;
            R += 1;
            return;
        }

        /* if (fence.size() == 1) {
            R += 1;
            return;
        } */
    }

    for (int i = 1; i <= remaining; ++i) {
        fence.push_back(i);

        calculate(remaining - i);
        fence.pop_back();
        // calculate(index + 1, remaining - i);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> S;

    calculate(S);

    std::cout << R << std::endl;

    return 0;
}