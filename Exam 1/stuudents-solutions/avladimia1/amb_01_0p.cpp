#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <tuple>

using namespace std;

struct appartment {
    long long val;
    bool hasTV = false;

        friend bool operator<(const appartment& l, const appartment& r) {
        return l.val < r.val;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<appartment> arr(n-1);
    for (auto& el : arr) cin >> el.val;


    while (k > 0) {
        int max = arr[0].val, maxi = 0;
        for (int i = 1; i < n - 1; i++) {
            if (max < arr[i].val) {
                max = arr[i].val;
                maxi = i;
            }
        }

        arr[maxi].hasTV = 1;
        arr[maxi + 1].hasTV = 1;
        arr[maxi].val = 0;
        arr[maxi + 1].val = 0;
        k -= 2;
    }

    int max = arr[0].val;
    for (int i = 1; i < n - 1; i++) {
        if (max < arr[i].val) {
            max = arr[i].val;
        }
    }

    cout << max;

    return 0;
}