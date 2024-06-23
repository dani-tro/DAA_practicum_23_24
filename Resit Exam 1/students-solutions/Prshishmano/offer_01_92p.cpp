#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*int struva(vector<int> cena,int a,int b,int k){
    int cenata = 0;
    for (int i = a+(b-a)/k; i < b; i++) {
        cenata += cena[i];
    }
    return cenata;
}*/

int malko = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> cena(n);
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
   /* for(int i = 2; i < n/k;i++){
        for(int j = 0; j < i;j++){
            cur += struva(cena,j,j+)
        }
    }*/


    cout << malko;
    
    return 0;
}
