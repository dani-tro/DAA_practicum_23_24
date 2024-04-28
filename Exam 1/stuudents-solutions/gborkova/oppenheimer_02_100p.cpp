#include <bits/stdc++.h>
#define MAX (unsigned long long)1e5

using namespace std;

long long A[MAX];
long long n, k;

int main() {
    scanf("%lld %lld", &n, &k);
    for (long long i = 0; i < n; ++i) {
        scanf("%lld", &A[i]);
    }

    sort(A, A+n);
    long long cnt = 0;
    long long p = 0, q = 0;
    while (q <= n-1) {
        if (A[q] - A[p] <= k) {
            cnt = max(cnt, q-p+1);
            q++;
        }
        else {
            p++;
        }
    }

    printf("%lld", cnt);

    return 0;
}
