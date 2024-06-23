#include <vector>
#include <iostream>

int N = 0;
int A = 0;
int B = 0;
int X = 0;
int R = 0;

std::vector<int> numbers;
std::vector<int> prefix;

int dp[100][100] = { { 0 } };

bool modified[200];

void print() {
    std::cout << "The prefix sums are: ";

    for (std::size_t i = 0; i < prefix.size(); ++i) {
        std::cout << prefix[i] << ' ';
    }

    std::cout << std::endl;
}

void getSumsSize(int size) {
    for (int i = size; i < prefix.size(); ++i) {
        int sum = 0;

        /* if (i - size - 1 < 0) {
            std::cout << prefix[i] << ' ';
            continue;
            sum = prefix[i];
        } else {
            
        } */

        if (i - size - 1 < 0) {
            sum = prefix[i];
        } else {
            sum = prefix[i] - prefix[i - size - 1];
        }

        if (sum >= A && sum <= B) {
            if (modified[sum] == false) {
                R += 1;
                modified[sum] = true;
            }
        }

        // std::cout << sum << ' ';

        // std::cout << prefix[i] - prefix[i - size - 1] << ' ';
    }

    // std::cout << std::endl;
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

    // getSumsSize(6);

    for (int i = 0; i < N; ++i) {
        getSumsSize(i);
    }

    /* for (int i = 0; i < N; ++i) {
        for (int j = 0; j < prefix.size(); ++j) {
            int sum = prefix[j] - prefix[i];

            if (j - i <= 0) {
                sum = prefix[j];
            }

            if (sum >= A && sum <= B) {
                if (modified[sum] == false) {
                    R += 1;
                    modified[sum] = true;
                } 
            }

            std::cout << sum << ' ';
        }

        std::cout << std::endl;
    } */

    std::cout << R << std::endl;

    return 0;
}
