# include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
long long a[maxn];
int main() {
    int n;
    long long ans = 0;
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++) {
            cin >> a[i];
    }

    long long sum = 0;

    for(i = 1; i <= n ; i++) {
        sum = 0;
        for (j = i; j <= n; j++) {
            sum += a[j];
            if (((j-i+1) % 2) == 1) {
                //cout << i << " " << j << " " << sum << endl;
                ans += sum;
            }
        }
    }

    cout << ans << endl;
}
