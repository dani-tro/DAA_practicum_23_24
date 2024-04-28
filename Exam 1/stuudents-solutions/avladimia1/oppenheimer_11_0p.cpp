#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <tuple>

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

        long long cal1 = arr[h] - arr[l + 1], cal2 = arr[h - 1] - arr[l];

        if (k >= cal1 && cal1 > cal2) {
            l++;
            break;
        }
        else if (k >= cal2 && cal2 > cal1) {
            h--;
            break;
        }
        else if (cal1 > cal2) {
            h--;
        }
        else if (cal1 < cal2) {
            l++;
        }
        else {
            h--;
            l++;
        }
    }

    cout << h - l + 1;

    return 0;
}