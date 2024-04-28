#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5+5;

long long arr[N];

long long i, n, k;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    i = 0;
    while (i < n) cin >> arr[i++];

    sort(arr, arr + n);
    
    long long maxElem = arr[n - 1];

    i = n - 2;

    long long cnt1 = 1;
    while (maxElem - arr[i--] <= k) {
        cnt1++;
    }

    i = 1;
    long long cnt2 = 1;
    long long minElem = arr[0];
    while (i < n && arr[i] - minElem <= k) {
        i++;
        cnt2++;
    }

    cout << max(cnt1, cnt2);

    return 0;
}
