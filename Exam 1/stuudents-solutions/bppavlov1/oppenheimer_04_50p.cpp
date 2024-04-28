#include <bits/stdc++.h>

using namespace std;

long long n, k, a[10001];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> k;
    for(long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    long long count = 1, maxCount = 0;
    for(long long i = 0; i < n; i++) {
        for(long long j = i + 1; j < n; j++) {
            if (a[j] - a[i] <= k) count++;
            else break;
        }
        if (maxCount < count && count >= 2) maxCount = count;
        count = 1;
    }

    cout << maxCount << endl;
}

/*
10 4
5 9 3 1 2 7 8 9 5 8
1 2 3 5 5 7 8 8 9 9
*/