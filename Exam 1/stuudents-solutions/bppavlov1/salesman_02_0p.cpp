#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct stock {
    double kg;
    double price;
    int index;

    stock() : kg(0), price(0), index(0) {}
    stock(double kg, double price, int index) : kg(kg), price(price), index(index) {}

    bool operator<(const stock& other) const {
        return price > other.price;
    }
};

struct stockByIndex {
    double kg;
    double price;
    int index;

    stockByIndex() : kg(0), price(0), index(0) {}
    stockByIndex(double kg, double price, int index) : kg(kg), price(price), index(index) {}

    bool operator<(const stockByIndex& other) const {
        return index < other.index;
    }
};

int m, n;
stock stocks[101];
stockByIndex picked[101];

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> m >> n;
    double a, b;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        stocks[i] = stock(a, b, i);
    }
    int i = 0;
    sort(stocks, stocks + n);

    double sum = 0.0;
    for(; i < n; i++) {
        // cout << stocks[i].kg << " " << stocks[i].price << endl;
        if (m == 0) break;
        if (stocks[i].kg <= m) {
            picked[i] = stockByIndex(stocks[i].kg, stocks[i].price, stocks[i].index);
            m -= stocks[i].kg;
        } else {
            picked[i] = stockByIndex(m, stocks[i].price, stocks[i].index);
            m = 0;
        }
        sum += picked[i].kg * picked[i].price;
    }

    sort(picked, picked + i);
    cout << fixed << setprecision(2) << sum << endl;
    for(int j = 0; j < i; j++) {
        cout << fixed << setprecision(3) << picked[j].kg << endl;
    }

    return 0;
}
