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
    ll l = -m;
    ll jl = 1;
    ll r = m;
    ll jr = 1;
    while (jr <= n && m <= pref[jr + 1]) {
        jr++;
    }
    ll curr = 0;
    pair<ll, ll> prev = { -1, -1 };
    ll segments = 1;
    for (ll i = 2; i <= n; i++) {
        l += d[i - 1];
        r += d[i - 1];
        while (jl <= n && l < pref[jl]) {
            jl++;
        }
        while (jr <= n && r <= pref[jr + 1]) {
            jr++;
        }
        pair<ll, ll> inter = intersect(prev, { jl, jr });
        if (inter.first > inter.second) {
            segments++;
            prev = { jl, jr };
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

    ll l = 0, r = pref[n], ans = -1;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (check(m)) {
            ans = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    cout << ans << endl;

}