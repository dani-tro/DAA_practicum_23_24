#include <iostream>
#include <iomanip>
#include <algorithm>
typedef long long ll;
using namespace std;

ll a[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    for (ll i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    ll j = 0, maxSize = 0;
    for (ll i = 0; i < n; i++) {
        while (j < n && a[j] - a[i] <= k) {
            maxSize = max(maxSize, j - i + 1);
            j++;
        }
    }
    cout << maxSize << endl;
}