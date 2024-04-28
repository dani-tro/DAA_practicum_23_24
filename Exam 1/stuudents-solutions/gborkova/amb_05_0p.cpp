#include <bits/stdc++.h>
#define MAX (unsigned long long)1e5

using namespace std;

long long A[MAX];
int n, k;

//long long dist = 0;

bool calc(long long dist) {
    bool res = false;
    int tv_cnt = k;
    long long tv_pos = -dist - 1;
    long long path = 0;
    for (int i = 0; i < n-1; ++i) {
        if (path - tv_pos > dist) {
            if (tv_cnt > 0) tv_cnt--; else return false;
            path += A[i];
            if (A[i] <= dist) {
                if (A[i] == dist) res = true;
                ++i;
                path += A[i];
            }
            tv_pos = A[i-1];
        }
        else if (path - tv_pos == dist) {
            res = true;
            if (tv_cnt > 0) tv_cnt--; else return false;
            path += A[i];
            if (A[i] <= dist) {
                if (A[i] == dist) res = true;
                ++i;
                path += A[i];
            }
            tv_pos = A[i-1];
        }
        else {
            //
        }
    }

    return res;
}

int main() {
    scanf("%i %i", &n, &k);
    for (long long i = 0; i < n-1; ++i) {
        scanf("%lld", &A[i]);
    }

    long long opt = 1e5;

    int l = 0, r = 1e5, mid;
    /*while (l <= r) {
        mid = (l + r) / 2;
        if (calc(mid)) {
            opt = mid;
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }*/

    for (long long i = 0; i < 1e9; ++i) {
        if (calc(i)) {
            printf("%lld", i);
            break;
        }
    }


    //printf("%lld", opt);

    return 0;
}
