#include <iostream>

#include <vector>

#include <algorithm>

struct Point {
    unsigned long long x        = 0;    // Coordinate.
    unsigned long long index    = 0;    // Index.

    bool operator<(const Point& instance) {
        return this->x < instance.x;
    }
};

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

unsigned long long A = 0;

unsigned long long L = 0;
unsigned long long R = 0;

std::vector<unsigned long long> arr;

std::vector<Point>  points;
std::vector<Pair>   pairs;

void buildHistogram() {
    for (unsigned long long i = points.front().x; i <= points.back().x; ++i) {
        pairs.push_back({ i, 0, i - 1 });
    }

    for (unsigned long long i = 0; i < points.size(); ++i) {
        pairs[points[i].x - 1].t += 1;
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

            if (arr[index] != 0 && K > 0) {
                arr[index] = arr[index] - 1;
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
        sum = sum + arr[index] * pairs[i].t;
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
        arr.push_back(A);
    }

    for (unsigned long long i = 0; i < M; ++i) {
        std::cin >> L >> R;
        points.push_back({ L, i });

        if (L < R) {
            for (unsigned long long j = L + 1; j < R; ++j) {
                points.push_back({ j, 0 });
            }
        }

        points.push_back({ R, i });
    }

    std::sort(points.begin(), points.end());

    buildHistogram();
    
    // showHistogram();

    std::cout << findMinimum() << std::endl;

    return 0;
}