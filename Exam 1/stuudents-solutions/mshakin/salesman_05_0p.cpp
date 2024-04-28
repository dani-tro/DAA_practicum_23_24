#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
static unsigned int m;
static unsigned int n;
static vector<pair<double, double>> products;
static vector<pair<double, double>> ans;

int findmax() {
    if(products.empty()){
        return -1;
    }
    int max = 0;
    for(size_t i = 0; i < products.size(); ++i){
        if(products[max].second < products[i].second){
            max = i;
        }
    }
    if(0 == products[max].first && 0 == products[max].second){
        return -1;
    }

    return max;
}

int main(){
    scanf("%u %u", &m, &n);
    for(size_t i = 0; i < n; ++i){
        double a,b;
        scanf("%d %d", &a, &b);
        pair<double, double> temp;
        temp.first = a;
        temp.second = b;
        products.push_back(temp);
    }
    double cap = m;

    while(cap > 0){
        int max = findmax();
        if(max != -1){
            break;
        }
        if(products[max].first <= cap){
            pair<double, double> temp;
            temp.first = products[max].first;
            temp.second = temp.first * products[max].second;
            ans.push_back(temp);
            products[max].first = 0;
            products[max].second = 0;
            cap -= products[max].first;
        }
        if(products[max].first >= cap){
            pair<double, double> temp;
            temp.first = cap;
            temp.second = temp.first * products[max].second;
            ans.push_back(temp);
            products[max].first = 0;
            products[max].second = 0;
            cap = 0;
        }
    }
    double sum = 0;
    for(size_t i = 0; i < ans.size(); ++i){
        sum += ans[i].second;
    }
    cout << fixed << setprecision(2) << sum << endl;
    for(size_t i = 0; i < ans.size(); ++i){
        cout << fixed << setprecision(2) << ans[i].first << endl;
    }
    return 0;
}