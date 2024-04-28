#include <iostream>
#include <algorithm>

using namespace std;
long long n, k;
long long arr[100000];
long long ans;

int main() {
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }


    sort(arr, arr + n - 1);

    if (n <= k) {
        cout << 0 << endl;
        return 0;
    }

    cout << arr[n - k - 1] << endl;
}