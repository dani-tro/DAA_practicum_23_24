#include <vector>
#include <iostream>

int N = 0;
int A = 0;
int B = 0;
int X = 0;
int R = 0;

std::vector<int> numbers;

bool modified[205] = { false };

void backtrack(int index, int sum) {
    if (index == numbers.size()) {
        if (sum >= A && sum <= B && modified[sum] == false) {
            R += 1;
            modified[sum] = true;
        }

        return;
    }

    backtrack(index + 1, sum + numbers[index]);
    backtrack(index + 1, sum);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N >> A >> B;

    for (std::size_t i = 0; i < N; ++i) {
        std::cin >> X;
        numbers.push_back(X);
    }

    backtrack(0, 0);

    std::cout << R << std::endl;

    return 0;
}
