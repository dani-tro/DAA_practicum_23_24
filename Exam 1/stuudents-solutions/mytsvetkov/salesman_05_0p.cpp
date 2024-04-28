#include <bits/stdc++.h>
using namespace std;

struct stock{
    double kilos;
    double perKilo;
    int index;
    double bought;

    bool operator<(const stock& other) {
        if(perKilo >= other.perKilo) return true;
        if(kilos < other.kilos) return true;
        if(index < other.index) return true;
        return false;
    }
};

double capacity;
int n;
vector<stock> stocks;

int main(){

    cin >> capacity;
    cin >> n;

    for(int i = 0; i < n; i++) {
        double k, pk;
        cin >> k >> pk;
        stocks.push_back({k, pk, i, 0});
    }

    sort(stocks.begin(), stocks.end());

    double totalProfit = 0;
    for(int i = 0; i < n && capacity > 0; i++) {
        totalProfit += min((double) capacity, stocks[i].kilos) * stocks[i].perKilo;
        stocks[i].bought = min((double) capacity, stocks[i].kilos);
        capacity -= min((double) capacity, stocks[i].kilos);
    }

    cout << fixed << setprecision(2) << totalProfit << endl;

    sort(stocks.begin(), stocks.end(), [](stock a, stock b) {
        return a.index < b.index;   
    });

    for(int i = 0; i < n; i++) {
        cout << fixed << setprecision(3) << stocks[i].bought << endl;
    }

    return 0;
}