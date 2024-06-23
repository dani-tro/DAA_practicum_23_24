#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

ll n,p;
ll t[100005], w[100005];

bool isPossible(int c) {
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += ((c - w[i]) / t[i]);
        if (sum >= p) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> p;

    for (int i = 1; i <= n; i++) cin >> t[i] >> w[i];

    ll l = 1, r = 1000001;
    ll mid;
    while(l <= r) {
        mid = (l + r) / 2;
        if (isPossible(mid)) r = mid - 1;
        else l = mid + 1;
    }

    std::cout << l << endl;

    return 0;
}