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

ll binHigher(ll i, ll t) {
    ll l = i, r = n, ans = i;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (pref[m] - pref[i] == t) {
            return m;
        }
        else if (pref[m] - pref[i] < t) {
            ans = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return ans;
}

ll binLower(ll i, ll t) {
    ll l = 1, r = i, ans = i;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (pref[i] - pref[m] == t) {
            return m;
        }
        else if (pref[i] - pref[m] < t) {
            ans = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return ans;
}

bool check(ll m) {
    pair<ll, ll> prev = { -1, -1 };
    ll segments = 0;
    for (ll i = 1; i <= n; i++) {
        ll l = binLower(i, m);
        //ll r = binHigher(i, m);
        ll r = 0;

        pair<ll, ll> inter = intersect(prev, {l, r});
        if (inter.first > inter.second) {
            segments++;
            prev = { l, r };
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