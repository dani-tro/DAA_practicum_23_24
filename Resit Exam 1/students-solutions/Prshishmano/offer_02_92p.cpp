#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long malko = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    vector<long> cena(n);
    for (int i = 0; i < n; i++) {
        cin >> cena[i];
    }
    
    sort(cena.begin(), cena.end());
    
    for(int i = 0;i < n;i++){
        malko += cena[i];
    }
    for(int i = n-k;i >0;i=i-k){
        malko -= cena[i];
    }

    cout << malko;
    
    return 0;
}