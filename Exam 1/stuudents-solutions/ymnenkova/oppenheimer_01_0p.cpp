#include <bits/stdc++.h>
using namespace std;

const long long MAX = 1e5+5;
long long atoms[MAX];
long long l[MAX];
long long r[MAX];

long long minDiff(long long arr[], long long size, long long diff) {
        if (arr[size - 1] - arr[0] > diff) {
            for (long long i = 0; i < size - 1; i++) {
                l[i] = arr[i];
                r[i] = arr[i + 1];
            }
            return max(minDiff(l, size -1, diff), minDiff(r, size -1, diff));
        }
        return size - 1;
    }

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N, K;
    cin >> N >> K;

    for (long long i = 0; i < N; i++) {
        cin >> atoms[i];
    }

    sort(atoms, atoms + N);
    cout << minDiff(atoms, N, K);

    return 0;
}