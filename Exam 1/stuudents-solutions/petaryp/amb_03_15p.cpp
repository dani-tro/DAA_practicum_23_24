#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

ll d[100005];
ll pref[100005];
ll n, k;
pair<ll, ll> line[200005];

bool check(ll m) {
    for (ll i = 1; i <= n; i++) {
        line[2 * i - 1] = { pref[i] - m, 0 };
        line[2 * i] = { pref[i] + m, 1 };
    }
    sort(line + 1, line + 2 * n + 1);

    ll curr = 0, segments = 1;
    for (ll i = 1; i <= 2 * n; i++) {
        if (line[i].second == 0) {
            curr++;
        }
        else {
            curr--;
        }
        if (curr == 0) {
            segments++;
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