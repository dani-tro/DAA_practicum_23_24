#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int n, m, p, a[MAXN];

int main(){

    int n;
    cin >> n >> m >> p;

    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    int sum = 0;
    for(int i = 0; i < m; i++) sum -= a[i];
    for(int i = m; i < n; i++) sum += a[i];

    cout << sum;

    return 0;
}
