#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int validni = 0;

    for (int l = 0; l < n; l++) {
        long long  suma = 0;
        for (int r = l + 1; r < n; r++) {
            suma += a[l] * a[r];
            if (suma >= k) {
                validni += (n - r);
                break;
            }
        }
    }

    cout << validni;

    return 0;
}
