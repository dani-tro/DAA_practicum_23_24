#include <bits/stdc++.h>
#define MAX (unsigned long long)1e5

using namespace std;

long long A[MAX];
int n, k;

bool calc(long long max_dist) {
    int tv_cnt = k;
    long long path = 0, tv_b = -1;
    if (A[0] > max_dist) {
        tv_cnt--;
        tv_b = max_dist;
    }
    else {
        tv_cnt--;
        tv_b = A[0] + max_dist;
    }

    for (int i = 1; i <= n-1; ++i) {
        path += A[i-1];
        if (path > tv_b) {
            if (tv_cnt > 0) tv_cnt--;
            else return false;
            tv_b = path + max_dist;
        }
    }

    return true;
}

int main() {
    scanf("%i %i", &n, &k);
    for (long long i = 0; i < n-1; ++i) {
        scanf("%lld", &A[i]);
    }

    int opt = 1e5;

    int l = 0, r = 1e5, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (calc(mid)) {
            opt = mid;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }

    printf("%i", opt);

    return 0;
}
