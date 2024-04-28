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
    ll i = 0;
    while (left > 0 && i < n) {
        if (left < q[c[i].second]) {
            maxPrice += left * c[i].first;
            q[c[i].second] = left;
            left = -5;
        }
        else {
            maxPrice += q[c[i].second] * c[i].first;
            left -= q[c[i].second];
            i++;
        }
    }
    for (; i < n; i++) {
        q[c[i].second] = 0;
    }

    cout << fixed << setprecision(2) << maxPrice << endl;
    for (ll i = 0; i < n; i++) {
        cout << fixed << setprecision(3) << q[i] << endl;
    }
}