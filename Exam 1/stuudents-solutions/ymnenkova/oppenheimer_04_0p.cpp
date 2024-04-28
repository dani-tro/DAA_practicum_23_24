#include <bits/stdc++.h>
using namespace std;

const long long MAX = 1e5+5;
long long atoms[MAX];

long long minDiff(long long arr[], long long begin, long long end, long long diff) {
    if (arr[end] - arr[begin] > diff) {
        return max(minDiff(atoms, begin, end - 1, diff), minDiff(atoms, begin + 1, end, diff));
    }
    return end - begin + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N, K;
    cin >> N >> K;

    for (long long i = 0; i < N; i++) {
        cin >> atoms[i];
    }

    sort(atoms, atoms + N);
    cout << minDiff(atoms, 0, N - 1, K);

    return 0;
}