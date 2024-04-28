#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

ll d[100005];
ll pref[100005];
ll n, k;

pair<ll, ll> intersect(pair<ll, ll> one, pair<ll, ll> two) {
    return { max(one.first, two.first), min(one.second, two.second) };
}

bool check(ll m) {
    pair<ll, ll> prev = { -1, -1 };
    ll segments = 0;
    for (ll i = 1; i <= n; i++) {
        pair<ll, ll> inter = intersect(prev, { pref[i] - m, pref[i] + m });
        if (inter.first > inter.second) {
            segments++;
            prev = { pref[i] - m, pref[i] + m };
        }
    }
    return segments <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    for (ll i = 1; i <= n - 1; i++) {
        cin >> d[i];
        pref[i + 1] = pref[i] + d[i];
    }

    if (k == n) {
        cout << 0 << endl;
        return 0;
    }
    ll s = n / (1 + k) + 1;
    cout << (s - 1) * d[1] << endl;
}