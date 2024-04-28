#include <iostream>
#include <algorithm>

using namespace std;

void fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int n, k;

int c[100005];

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c, c+n);

    int l = 0;
    int r = 1;

    int maxl = 0;

    while(r < n) {
        if(c[r] - c[l] <= k) {
            r++;
        }
        else {
            maxl = max(maxl, r - l);
            l++;
        }

        if(l == r) break;
    }
    maxl = max(maxl, r - l);

    cout << maxl << "\n";

    return 0;
}