#include <vector>
#include <iostream>

int N = 0;
int A = 0;
int B = 0;
int X = 0;
int R = 0;

std::vector<int> numbers;
std::vector<int> prefix;

int dp[100] = { 0 };

bool modified[200] = { false };

void print() {
    std::cout << "The prefix sums are: ";

    for (std::size_t i = 0; i < prefix.size(); ++i) {
        std::cout << prefix[i] << ' ';
    }

    std::cout << std::endl;
}

bool contains(int sum) {
    return sum >= A && sum <= B;
}

void calculate(int size) {
    for (int i = 0; i < numbers.size(); ++i) {
        int sum = 0;

        for (int j = i; j < size; ++j) {
            sum += numbers[j];
        }

        std::cout << sum << std::endl;

        if (contains(sum)) {
            R += 1;
        }
    }
}

void getSums(int size) {
    for (int i = 0; i < numbers.size(); ++i) {
        int sum = 0;

        for (int j = i; j < size; ++j) {
            sum += numbers[j];
        }

        std::cout << sum << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N >> A >> B;

    for (std::size_t i = 0; i < N; ++i) {
        std::cin >> X;
        numbers.push_back(X);

        if (i == 0) {
            prefix.push_back(X);
        } else {
            int previous = prefix.back();
            prefix.push_back(X + previous);
        }
    }

    // print();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < prefix.size(); ++j) {
            int sum = prefix[j] - prefix[i];

            if (prefix[j] - prefix[i] < 0) {
                sum = prefix[j];
            }

            if (sum >= A && sum <= B) {
                if (modified[sum] == false) {
                    R += 1;
                    modified[sum] = true;
                } 
            }

            // std::cout << sum << ' ';
        }

        // std::cout << std::endl;
    }

    std::cout << R << std::endl;

    return 0;
}
