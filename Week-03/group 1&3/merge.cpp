// O(n+m)

# include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
int a[MAXN], b[MAXN];
int main() {
    ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]){
            cout << a[i] << " ";
            i ++;
        } else {
            cout << b[j] << " ";
            j ++;
        }
    }

    for (;i < n; i++) cout << a[i] << " ";
    for (;j < m; j++) cout << b[j] << " ";

    cout << endl;
    return 0;
}
