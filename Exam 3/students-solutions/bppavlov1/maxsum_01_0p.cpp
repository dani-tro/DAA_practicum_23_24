#include <iostream>

using namespace std;

int n,k;
int a[100001], b[1001];
int leftA[100004], rightA[100004];

void calcLeft(int idx) {
    for(int i = 1; i <= k; i++) {
        if (idx + b[i] > n) return;
        leftA[idx + b[i]] = max(leftA[idx + b[i]], leftA[idx] + a[idx + b[i]]);
        // cout << idx << " " << leftA[idx] << " " << idx+b[i] << " " << leftA[idx+b[i]] << endl;
        calcLeft(idx + b[i]);
    }
}

void calcRight(int idx) {
    for(int i = 1; i <= k; i++) {
        if (idx - b[i] < 0) return;
        rightA[idx - b[i]] = max(rightA[idx - b[i]], rightA[idx] + a[idx - b[i]]);
        calcRight(idx - b[i]);
    }
}


int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];

    leftA[1] = a[1];
    rightA[n] = a[n];

    calcLeft(1);
    calcRight(n);

    // cout << rightA[n-5] << endl;

    int max = -INT_MAX;
    for(int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (max < leftA[i] + rightA[j]) {
                max = leftA[i] + rightA[j];
            }
        }
    }

    cout << max << endl;

    return 0;
}