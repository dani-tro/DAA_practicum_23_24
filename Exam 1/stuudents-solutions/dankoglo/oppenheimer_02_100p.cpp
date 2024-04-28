#include <iostream>
#include <algorithm>

using namespace std;

void fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

long long n, k;

long long c[100005];

int main()
{
    cin >> n >> k;
    for(long long i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c, c+n);

    long long l = 0;
    long long r = 1;

    long long maxl = 0;

    while(r < n) {
        if(c[r] - c[l] <= k) {
            r++;
        }
        else {
            maxl = max(maxl, r - l);
            l++;
        }

        //if(l == r) r++;
    }
    maxl = max(maxl, r - l);

    cout << maxl << "\n";

    return 0;
}