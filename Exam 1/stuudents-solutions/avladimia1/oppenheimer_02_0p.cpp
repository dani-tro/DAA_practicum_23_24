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

    int l = 0, h = n - 1;

    while (l < h) {
        if ((arr[h] - arr[l]) <= k) break;

        long long cal1 = arr[l + 1] + arr[h], cal2 = arr[l] + arr[h - 1];

        if (cal1 > cal2) {
            l++;
        }
        else {
            h--;
        }
    }

    cout << h - l + 1;

    return 0;
}