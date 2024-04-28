#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
typedef long long ll;
using namespace std;

pair<double, ll> c[100];
double q[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll m, n;
    cin >> m >> n;

    for (ll i = 0; i < n; i++) {
        double cc;
        cin >> q[i] >> cc;
        c[i] = { cc, i };
    }

    sort(c, c + n, greater<>());

    double maxPrice = 0, left = m;
    ll j = 0;
    while (left > 0 && j < n) {
        if (left < q[c[j].second]) {
            maxPrice += left * c[j].first;
            q[c[j].second] = left;
            left = -5;
        }
        else {
            maxPrice += q[c[j].second] * c[j].first;
            left -= q[c[j].second];
        }
        j++;
    }
    for (; j < n; j++) {
        q[c[j].second] = 0;
    }

    cout << fixed << setprecision(2) << maxPrice << endl;
    for (ll i = 0; i < n; i++) {
        cout << fixed << setprecision(3) << q[i] << endl;
    }
}