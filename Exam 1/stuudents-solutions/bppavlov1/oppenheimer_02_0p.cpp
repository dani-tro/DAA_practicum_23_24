#include <bits/stdc++.h>

using namespace std;

int n, k, a[10001];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int count = 1, maxCount = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if (a[j] - a[i] <= k) count++;
            else break;
        }
        if (maxCount < count && count >= 2) maxCount = count;
        count = 1;
    }

    cout << maxCount << endl;
}
