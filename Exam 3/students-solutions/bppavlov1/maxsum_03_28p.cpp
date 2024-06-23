#include <iostream>
#include <climits>

using namespace std;

long long n,k;
long long a[100001], b[1001];
long long leftA[100004], rightA[100004];

void calcLeft(long long idx) {
    for(long long i = 1; i <= k; i++) {
        if (idx + b[i] > n) return;
        leftA[idx + b[i]] = max(leftA[idx + b[i]], leftA[idx] + a[idx + b[i]]);
        // cout << idx << " " << leftA[idx] << " " << idx+b[i] << " " << leftA[idx+b[i]] << endl;
        calcLeft(idx + b[i]);
    }
}

void calcRight(long long idx) {
    for(long long i = 1; i <= k; i++) {
        if (idx - b[i] < 0) return;
        rightA[idx - b[i]] = max(rightA[idx - b[i]], rightA[idx] + a[idx - b[i]]);
        calcRight(idx - b[i]);
    }
}


int main() {
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 1; i <= k; i++) cin >> b[i];

    leftA[1] = a[1];
    rightA[n] = a[n];

    calcLeft(1);
    calcRight(n);

    // cout << rightA[n-5] << endl;

    long long max = -LLONG_MAX;
    for(long long i = 1; i <= n; i++) {
        for (long long j = i + 1; j <= n; j++) {
            if (max < leftA[i] + rightA[j]) {
                max = leftA[i] + rightA[j];
            }
        }
    }

    cout << max << endl;

    return 0;
}