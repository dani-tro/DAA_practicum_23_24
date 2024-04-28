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
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }
    arr[n - 1] = 0;

    while (k > 0) {
        int maxt = arr[0];
        int maxi = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > maxt) {
                maxt = arr[i];
                maxi = i;
            }
        }

        arr[maxi] = 0;
        arr[maxi + 1] = 0;
        k -= 2;
    }

    int maxt = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxt) {
            maxt = arr[i];
        }
    }

    cout << maxt;

    return 0;
}