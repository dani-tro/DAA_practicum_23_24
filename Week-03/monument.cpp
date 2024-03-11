// O(n)

# include <bits/stdc++.h>
using namespace std;

#define MAX 310000

long long n, r, a[MAX], ans, j;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> r;
    for(int i = 0; i < n; i++)cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        while(j < n && a[j] - a[i] <= r)j++;
        ans += n - j;
    }

    cout << ans << endl;

    return 0;
}
