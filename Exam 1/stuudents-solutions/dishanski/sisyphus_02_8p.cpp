#include <iostream>

#include <vector>

#include <algorithm>

struct Pair {
    unsigned long long p    =   0;
    unsigned long long t    =   0;
    unsigned long long k    =   0;

    bool operator<(const Pair& instance) {
        return this->t < instance.t;
    }
};

unsigned long long N = 0;
unsigned long long M = 0;
unsigned long long K = 0;

unsigned long A = 0;

unsigned long L = 0;
unsigned long R = 0;

std::vector<unsigned long> arr1;
std::vector<unsigned long> arr2;

std::vector<Pair>   pairs;

void buildHistogram() {
    for (unsigned long long i = arr2.front(); i <= arr2.back(); ++i) {
        pairs.push_back({ i, 0, i - 1 });
    }

    for (unsigned long long i = 0; i < arr2.size(); ++i) {
        pairs[arr2[i] - 1].t += 1;
    }

    std::sort(pairs.begin(), pairs.end());
}

void showHistogram() {
    for (std::size_t i = 0; i < pairs.size(); ++i) {
        std::cout << "Key - Value is: " << pairs[i].p << ' ' << pairs[i].t << ' ' << pairs[i].k << std::endl;
    }
}

unsigned long long findMinimum() {
    while (K > 0) {
        bool flag = false;

        for (long long i = pairs.size() - 1; i >= 0; --i) {
            unsigned long long index = pairs[i].k;

            if (arr1[index] != 0 && K > 0) {
                arr1[index] = arr1[index] - 1;
                // pairs[i].t = pairs[i].t - 1;
                K = K - 1;
                flag = true;
            }
        }

        if (flag == false) {
            break;
        }
    }

    // std::cout << "The array is: ";

    /* for (unsigned long long i = 0; i < N; ++i) {
        std::cout << 
    } */

    unsigned long long sum = 0;

    for (unsigned long long i = 0; i < N; ++i) {
        unsigned long long index = pairs[i].k;
        // std::cout << "The index here is: " << index << ' ' << arr[index] << ' ' << pairs[i].t << std::endl;
        sum = sum + arr1[index] * pairs[i].t;
    }

    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N >> M >> K;

    for (unsigned long long i = 0; i < N; ++i) {
        std::cin >> A;
        arr1.push_back(A);
    }

    for (unsigned long long i = 0; i < M; ++i) {
        std::cin >> L >> R;

        if (i == 0) {
            if (L > 1) {
                for (unsigned long long j = 1; j < L; ++j) {
                    arr2.push_back(j);
                }
            }
        } else {
            if (arr2.back() < L) {
                for (unsigned long long j = arr2[i - 1] + 1; j < L; ++j) {
                    arr2.push_back(j);
                }
            }
        }

        arr2.push_back(L);

        if (L < R) {
            for (unsigned long long j = L + 1; j < R; ++j) {
                arr2.push_back(j);
            }
        }

        arr2.push_back(R);

        
    }

    std::sort(arr2.begin(), arr2.end());

    /* for (unsigned long long i = 0; i < arr2.size(); ++i) {
        std::cout << arr2[i] << ' ';
    } */

    buildHistogram();
    
    // showHistogram();

    std::cout << findMinimum() << std::endl;

    return 0;
}
