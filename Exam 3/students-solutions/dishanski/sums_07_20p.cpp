#include <vector>
#include <iostream>

int N = 0;
int A = 0;
int B = 0;
int X = 0;
int R = 0;

int prefix[100] = { 0 };
bool modified[205] = { false };

void print() {
    std::cout << "The prefix sums are: ";

    for (std::size_t i = 0; i < N; ++i) {
        std::cout << prefix[i] << ' ';
    }

    std::cout << std::endl;
}

void getSumsSize(int size) {
    // std::cout << "Size " << size + 1 << ": "; 

    for (int i = size; i < N; ++i) {
        long long sum = 0;

        if (i - size - 1 < 0) {
            sum = prefix[i];
        } else {
            sum = prefix[i] - prefix[i - size - 1];
        }

        if (sum >= A && sum <= B && modified[sum] == false) {
            modified[sum] = true;
            // R += 1;
        }

        // std::cout << sum << ' ';
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

        if (i == 0) {
            prefix[i] = X;
        } else {
            prefix[i] = X + prefix[i - 1];
        }
    }

    // print();

    for (int i = 0; i < N; ++i) {
        getSumsSize(i);
    }

    for (int i = 0; i < 205; ++i) {
        R += modified[i];
    }

    std::cout << R << std::endl;

    return 0;
}
