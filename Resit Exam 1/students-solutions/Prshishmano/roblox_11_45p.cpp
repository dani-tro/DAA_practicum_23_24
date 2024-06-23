#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long a[10000000];
long long starekshun[10000000];
int n;
long long k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    starekshun[0] = a[0];
    for (int i = 1; i < n; ++i) {
        starekshun[i] = starekshun[i - 1] + a[i];
    }

    long long count = 0;

    for (int l = 0; l < n; ++l) {
        long long suma = 0;
        for (int r = l + 1; r < n; ++r) {
            suma += (starekshun[r-1] - starekshun[l-1]) * a[r];
            if (suma >= k) {
                count += (n - r);
                break;
            }
        }
    }

    cout << count;
    return 0;
}
