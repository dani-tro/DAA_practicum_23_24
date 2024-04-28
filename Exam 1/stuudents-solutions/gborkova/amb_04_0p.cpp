#include <bits/stdc++.h>
#define MAX (unsigned long long)1e5

using namespace std;

long long A[MAX];
int n, k;

long long dist = 0;

bool calc(long long max_dist) {
    dist = 0;
    int tv_cnt = k;
    int i = 0;
    long long path = A[0], tv_b = -1;
    if (A[0] > max_dist) {
        tv_cnt--;
        tv_b = max_dist;
    }
    else {
        tv_cnt--;
        tv_b = A[0] + max_dist;
        dist = max(dist, A[0]);
        i = 2;
    }

    for (; i <= n-1; ++i) {
        path += A[i-1];
        if (path > tv_b) {
            if (tv_cnt > 0) tv_cnt--;
            else return false;
            tv_b = path + max_dist;
        }
        else {
            dist = max(dist, A[i-1]);
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

    //calc(3);

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

    printf("%lld", dist);
    /*calc(1);
    printf("%lld", dist);
    calc(2);
    printf("%lld", dist);
    calc(3);
    printf("%lld", dist);
    calc(4);
    printf("%lld", dist);
    calc(5);*/

    return 0;
}
