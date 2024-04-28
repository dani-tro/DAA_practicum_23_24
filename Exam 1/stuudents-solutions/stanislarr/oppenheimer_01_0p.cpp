#include <iostream>
#include <algorithm>


using namespace std;
long long n, k;
long long arr[100000];
long long ans;

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long start = 0;
    long long end = 0;
    long long temp = 0;

    sort(arr, arr + n);

    while (end < n) {
        if (arr[end] - arr[start] <= k) {
            end++;
            temp++;

            ans = max(temp, ans);
        }
        else {
            temp = max(long long(0), temp - 1);
            start++;
        }
    }

    cout << ans << endl;
}
