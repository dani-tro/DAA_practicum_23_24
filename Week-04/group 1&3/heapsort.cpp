# include <bits/stdc++.h>
using namespace std;
int a[105];
void heapify (int curr) {
    if (curr == 1) return ;
    int par = curr / 2;
    if (a[par] <= a[curr]) return ;
    swap (a[par], a[curr]);
    heapify(par);
}

void soak(int curr, int n)
{
    int child = 2 * curr;
    if (child > n) return ;
    if (child + 1 <= n &&
        a[child] > a[child + 1]) child = child + 1;
    if (a[curr] > a[child]) {
        swap (a[curr], a[child]);
        soak (child, n);
    }
}
int main() {
    int n;
    int i;
    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];
    for (i = 2; i <= n; i++) heapify(i);
    for (i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;

    for (i = n; i > 1; i--) {
        swap (a[1], a[i]);
        soak (1, i - 1);
    }

    for (i = n; i >= 1; i--) cout << a[i] << " ";
    cout << endl;
}
