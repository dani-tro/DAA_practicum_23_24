#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (auto& el : arr) cin >> el;

    sort(arr.begin(), arr.end());

    int l1 = 0, h = n - 1;

    while (l1 < n) {
        if (arr[h] - arr[l1] > k) {
            l1++;
        }
        else break;
    }

    int l2 = 0;
    while (h >= 0) {
        if (arr[h] - arr[l2] > k) {
            h--;
        }
        else break;
    }

    cout << max(n - l1, h);

    return 0;
}