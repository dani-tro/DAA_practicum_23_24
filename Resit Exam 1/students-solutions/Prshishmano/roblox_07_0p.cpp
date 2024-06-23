#include <iostream>
#include <vector>

using namespace std;

/*long long ekshun(long long a[10000000],int l ,int r){
    long long suma = 0;
    for (int i = l; i < r; i++) {
        for (int j = i + 1; j <= r; j++) {
            suma += a[i] * a[j];
        }
    }
    return suma;
}*/

long long ekshun(long long a[10000000],int l ,int r,long long starekshun[1000000][1000000]){
    if(starekshun[l][r] == 0){
        starekshun[l][r] = starekshun[l][r-1];
        for(int i = l; i < r;i++){
            starekshun[l][r] += a[i]*a[r];
        }
    }
    return starekshun[l][r];
}

long long a[10000000];
long long starekshun[1000000][1000000] = {0};
int n;
long long k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long count = 0;
    
    for (int l = 0; l < n; ++l) {
        for (int r = l + 1; r < n; ++r) {
            if (ekshun(a,l,r,starekshun) >=k ) {
                //cout << l << " " << r <<"\n"; 
                count += (n - r);
                break;
            }
        }
    }

    cout << count;
    return 0;
}