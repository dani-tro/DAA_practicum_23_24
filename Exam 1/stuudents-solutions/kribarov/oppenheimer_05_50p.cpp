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
    
    long long maxCnt = 1;
    long long cnt = 1;
//    long long lastCnt;
    for (int j = 0; j < n - 1; j++) {
        long long minElem = arr[j];
        i = j + 1;
        cnt = 1;
        
        while (i < n && arr[i] - minElem <= k) {
            i++;
            cnt++;
        }

        if (maxCnt < cnt) {
            maxCnt = cnt;
        }

    }

    cout << maxCnt;


    return 0;
}