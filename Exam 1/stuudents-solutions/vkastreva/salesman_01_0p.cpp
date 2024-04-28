#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int n, m;
vector<double> prices;
vector<double> kilos;
struct item {
    double amount;
    double price;
    double used = 0;
    int index;
};
vector<item> items;
void input(){
    cin >> m >> n;
    items.resize(n);
    double price, amount;
    for(int i = 0; i < n; i++){
        cin >> amount >> price;
        items.push_back({amount, price});
    }
}

void solve(){
    sort(items.begin(), items.end(), []
    (item& i1, item& i2){
        return i1.price > i2.price || (i1.price == i2.price && i1.amount > i2.amount);
    });
    double dbM = (double)m;
    double currentSpent = 0;
    int i = 0;
    while(dbM > 0. && i < items.size()){
        if(dbM >= items[i].amount){
            currentSpent += items[i].amount * items[i].price;
            dbM -= items[i].amount;
            items[i].used = items[i].amount;
            i++;
        } else {
            currentSpent += dbM * items[i].price;
            items[i].used = dbM;
            dbM = 0;
        }
    }

    cout << fixed << setprecision(2)<< currentSpent << endl;
    sort(items.begin(), items.end(), []
    (item& i1, item& i2){
        return i1.index < i2.index;    });
    for(int i = 0; i < n; i++){
        cout << fixed << setprecision(3) << items[i].used << endl;
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    solve();


    return 0;
}
