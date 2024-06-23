#include <iostream>

using namespace std;

#define MOD 1000000007

int n;
long long counter = 0;

void calc(int prev, int current, int remaining) {
    // cout << current << " " << remaining << endl;
    if (current == 1 && remaining == 1) {
        return;
    }
    if (remaining == 0) {
        counter += 1;
        return;
    }
    for (int i = 1; i <= remaining; i++) {
        if ((prev < current || prev == -1) && current > i) {
            calc(current, i, remaining - i);
        } else if ((prev > current || prev == -1) && current < i) {
            calc(current, i, remaining - i);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) calc(-1, i, n - i);
    cout << (counter % MOD) << endl;
    return 0;
}