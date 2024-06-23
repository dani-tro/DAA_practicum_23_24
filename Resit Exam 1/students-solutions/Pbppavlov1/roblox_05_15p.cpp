#include <iostream>

using namespace std;

#define ll long long

ll n,k;
ll a[10000001];
ll prefix[10000001];

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

int getInfix(int left, int right) {
    int sum = 0;
    for(int i = 1; i <= left - 1; i++) {
        for(int j = left; j <= right; j++) {
            sum += (a[i] * a[j]);
        }
    }
    return prefix[right] - (sum + prefix[left-1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // prefix[i] = prefix[i-1] + a[i];
    }

    prefix[1] = 0;

    for (int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            prefix[i] += (a[j] * a[i]);
        }
        prefix[i] += prefix[i-1];
    }

    ll counter = 0;
    for (int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if (getInfix(i, j) >= k) {
                counter += (n - j + 1);
                break;
            } 
        }
    }

    cout << counter << endl;

    return 0;
}
