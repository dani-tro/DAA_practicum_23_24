#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;
double m, totalPrice;
int n;

struct Goods {
    double kilos;
    double price;
    double startingIndex;
    double totalBought = 0;

    Goods() {
        this->kilos = 0;
        this->price = 0;
        this->startingIndex = 0;
    }

    Goods(double k, double p, int i) {
        this->kilos = k;
        this->price = p;
        this->startingIndex = i;
    }

    bool operator<(const Goods& r) {
        return this->price > r.price;
    }
};

Goods arr[100];
Goods arrNoChange[100];

int main() {
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        double k, p;
        cin >> k >> p;

        arr[i] = Goods(k, p, i);
        arrNoChange[i] = Goods(k, p, i);
    }


    sort(arr, arr + n);

    for (int i = 0; i <= n; i++) {
        if (m <= 0) {
            break;
        }
        int index = arr[i].startingIndex;

        if (m < arr[i].kilos) {
            totalPrice += m * arr[i].price;
            arrNoChange[index].totalBought = m;
            m = 0;
        } else {
            m -= arr[i].kilos;
            arrNoChange[index].totalBought = arrNoChange[index].kilos;
            totalPrice += arr[i].kilos * arr[i].price;
        }
    }

    cout << fixed << setprecision(2) << totalPrice << endl;


    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(3) << arrNoChange[i].totalBought << endl;
    }
}