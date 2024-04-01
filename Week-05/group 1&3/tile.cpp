# include <bits/stdc++.h>
using namespace std;
long long a, k, b, m, x;
long long calc(long long days){
    return days * a + days * b - (days / k) * a - (days / m) * b;
}
int main(){
    cin >> a >> k >> b >> m >> x;
    long long l = 1;
    long long r = (2 * x) / (a + b) + 1;
    long long mid;
    while (l < r){
        mid = (l + r) / 2;
        if (calc(mid) >= x) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << l << endl;
}
