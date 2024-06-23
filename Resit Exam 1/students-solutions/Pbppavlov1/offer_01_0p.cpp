#include <iostream>

using namespace std;

int n,k;
int a[100001];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a, a + n + 1);

    int sum = 0;
    for(int i = n-k+1; i > 0; i-=k) {
        a[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        sum += a[i];
    }
    cout << sum << endl;

    return 0;
}