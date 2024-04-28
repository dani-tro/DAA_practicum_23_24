#include <bits/stdc++.h>
using namespace std;
 
int n, k, a[100000];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);
    int i = 0, j = 0, maxSize = 0;
 
    while (j < n) {
        if ((a[j] - a[i]) <= k) {
            maxSize = max(maxSize, j - i + 1);
            j++;
        }
        else {
            i++;
        }
    }
    cout << maxSize;
    return 0;
}