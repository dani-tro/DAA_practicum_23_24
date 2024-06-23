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

    vector<long> ekshun(n + 1, 0);
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            ekshun[i] += a[i] * a[j];
        }
        ekshun[i] += ekshun[i + 1];
    }

    int validni = 0;
    for (int i = 0; i < n; i++) {
        int start = i, stop = n;
        while (start < stop) {
            int mid = (start + stop) / 2;
            long long obshto = ekshun[i] - ekshun[mid + 1];
            if (obshto >= k) {
                stop = mid;
            } else {
                start = mid + 1;
            }
        }
        if (ekshun[i] - ekshun[start + 1] >= k) {
            validni += (n - start);
        }
    }

    cout << validni;

    return 0;
}
