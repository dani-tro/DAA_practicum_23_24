#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 10005;
unsigned long crit[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long k;
    int n, i;
    cin >> n >> k;
    for (i = 0; i < n; ++i) {
        cin >> crit[i];
    }

    int max = 1, l = 0;
    sort(crit, crit + n);


    for (i = 0; i < n; ++i) {
        if (crit[i] - crit[l] <= k && (i - l) + 1 > max) {
            max = (i - l) + 1;
        }
        while (crit[i] - crit[l] > k) {
            ++l;
        }
    }

    cout << max;

    return 0;
}

