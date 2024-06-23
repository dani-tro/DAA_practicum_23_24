#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

ll n,p;
ll t[100001], w[100001];

bool isPossible(int c) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        // cout << floor((c - w[i]) / t[i]) << endl;
        sum += floor((c - w[i]) / t[i]);
    }
    // cout << endl;
    return sum >= p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> p;

    for (int i = 1; i <= n; i++) cin >> t[i] >> w[i];

    ll l = 1, r = 100001;
    ll mid;
    while(l < r) {
        mid = (l + r) / 2;
        if (isPossible(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << r << endl;

    return 0;
}