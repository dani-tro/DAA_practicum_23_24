#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
typedef long long ll;
using namespace std;

ll n, m, k;
ll a[100001];
ll freq[100001];


vector<pair<ll, ll>> line, line2;
priority_queue<pair<ll, ll>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    for (ll i = 1; i <= n; i++) cin >> a[i];

    for (ll i = 1; i <= m; i++) {
        ll l, r;
        cin >> l >> r;
        line2.push_back({ l, r });
        line.push_back({ l, 0 });
        line.push_back({ r, 1 });
    }
    sort(line.begin(), line.end());

    //ll j = 0, curr = 0;
    //for (ll i = 1; i <= n; i++) {
    //    ll c = 0;
    //    while (j < 2 * m && line[j].first == i) {
    //        if (line[j].second == 0) {
    //            curr++;
    //        }
    //        else {
    //            curr--;
    //            c++;
    //        }
    //        j++;
    //    }
    //    freq[i] = c + curr;
    //}
    ll j = 1, curr = 0;
    for (ll i = 0; i < 2 * m; i++) {
        while (j < line[i].first) {
            freq[j] = curr;
            j++;
        }
        if (line[i].second == 0) {
            curr++;
        }
        else {
            curr--;
            freq[line[i].first]++;
        }

    }


    for (ll i = 1; i <= n; i++) {
        q.push({ freq[i], i });
    }


    /*for (ll i = 1; i <= n; i++) {
        cout << freq[i] << endl;
    }*/

    j = k;
    while (!q.empty() && j > 0) {
        pair<ll, ll> temp = q.top();
        q.pop();
        if (a[temp.second] >= k) {
            a[temp.second] -= k;
            j -= k;
        }
        else {
            a[temp.second] = 0;
            j -= a[temp.second];
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