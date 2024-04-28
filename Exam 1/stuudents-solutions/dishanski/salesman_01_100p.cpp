#include <iomanip>
#include <iostream>

#include <vector>

#include <algorithm>

double M = 0;
unsigned int N = 0;

struct Trade {
    double a = 0.0;
    double b = 0.0;
    
    std::size_t p = 0;

    bool operator<(const Trade& instance) {
        return this->b < instance.b;
    }
};

double A = 0;
double B = 0;

std::vector<Trade>  trades;
std::vector<double> taken;

void printTrades() {
    for (std::size_t i = 0; i < trades.size(); ++i) {
        std::cout << trades[i].a << ' ' << trades[i].b << std::endl;
    }
}

double findMax() {
    double sum = 0;

    for (int i = trades.size() - 1; i >= 0; --i) {
        if (trades[i].a <= M) {
            sum += trades[i].b * trades[i].a;
            M = M - trades[i].a;
            taken[trades[i].p] = trades[i].a;
        } else {
            sum += trades[i].b * M;
            taken[trades[i].p] = M;
            M = 0;
        }
    }

    return sum;
}

void printTaken() {
    for (std::size_t i = 0; i < N; ++i) {
        std::cout << std::fixed << std::setprecision(3) << taken[i] << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> M;
    std::cin >> N;

    for (std::size_t i = 0; i < N; ++i) {
        std::cin >> A >> B;
        trades.push_back({ A, B, i});
        taken.push_back(0.0);
    }

    std::sort(trades.begin(), trades.end());

    std::cout << std::fixed << std::setprecision(2) << findMax() << std::endl;
    printTaken();
    // printTrades();

    return 0;
}
