#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>
typedef long long ll;
using namespace std;

ll n, m, k;
ll a[100001];
ll freq[100001];

vector<pair<ll, ll>> line;
vector<pair<ll, ll>> line2;
priority_queue<array<ll, 3>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        line.push_back({ i, 0 });
    }

    for (ll i = 1; i <= m; i++) {
        ll l, r;
        cin >> l >> r;
        line2.push_back({ l, r });
        line.push_back({ l, -1 });
        line.push_back({ r, 1 });
    }
    sort(line.begin(), line.end());

    ll curr = 0;
    for (ll i = 0; i < 2 * m + n; i++) {
        if (line[i].second == 0) {
            freq[line[i].first] = curr;
        }
        else if (line[i].second == -1) curr++;
        else curr--;
    }

    for (ll i = 1; i <= n; i++) {
        q.push({ freq[i], a[i], i });
    }

    //for (ll i = 1; i <= n; i++) {
    //    cout << freq[i] << endl;
    //}

    ll j = k;
    while (!q.empty() && j > 0) {
        array<ll, 3> temp = q.top();
        q.pop();
        if (a[temp[2]] >= k) {
            a[temp[2]] -= k;
            j -= k;
        }
        else {
            a[temp[2]] = 0;
            j -= a[temp[2]];
        }
    }

    /*for (ll i = 1; i <= n; i++) {
        cout << a[i] << endl;
    }*/

    for (ll i = 1; i <= n; i++) {
        freq[i] = freq[i - 1] + a[i];
    }

    ll s = 0;
    freq[0] = 0;
    for (ll i = 0; i < m; i++) {
        s += freq[line2[i].second] - freq[line2[i].first - 1];
    }
    cout << s << endl;
}