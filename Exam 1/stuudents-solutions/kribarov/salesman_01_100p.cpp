#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

const int M = 1000;
const int N = 100;

struct Stock {
    double a, b;
    int idx;

    bool operator<(const Stock& o) const {
        return b >= o.b;
    }
};

double c[M];
Stock stocks[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    double m;
    cin >> m;

    int n;
    cin >> n;
    int i = 0;
    while (i < n) {
        double a, b;
        cin >> a;
        cin >> b;
        stocks[i] = {a, b, i};
        ++i;
    }

    std::sort(stocks, stocks + n);

    double ans = 0.0;

    for (int j = 0; j < n && m > 0; ++j) {


        if (stocks[j].a - m <= 0.00001) {
            c[stocks[j].idx] = stocks[j].a;

            m -= stocks[j].a;
            ans += stocks[j].a * stocks[j].b;

        } else if (stocks[j].a > m) {

            c[stocks[j].idx] = m;
            ans += stocks[j].b * m;
            m = 0;
        }

    }

    cout << fixed << setprecision(2) << ans << endl;
    int s = 0;
    while (s < n) {
        cout << fixed << setprecision(3) << c[s++] << endl;
    }

}