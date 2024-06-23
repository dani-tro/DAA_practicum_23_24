#include <iostream>

using namespace std;

#define ll long long

ll n,k;
ll a[10000001];

bool isPossible(int left, int right) {
    int sum = 0;
    for(int i = left; i <= right; i++) {
        for(int j = i + 1; j <= right; j++) {
            sum += a[i] * a[j];
            if (sum >= k) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> a[i];

    ll counter = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if (isPossible(i, j)) {
                counter += (n - j + 1);
                break;
            }
        }
    }

    cout << counter << endl;

    return 0;
}