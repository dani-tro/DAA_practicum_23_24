#include <bits/stdc++.h>

#define MAX 100

using namespace std;


int n, a, b;
int sums[MAX];
int seq[MAX];

int getSize() {
    int count = 0;
    for (int i = a; i <= b; i++) {
        if (sums[i] == 1) {
            //cout << i << endl;
            count++;
        };
    }
    return count;
}

void solve(int a, int b) {
    for (int i = 0; i < n; i++) {
        int number = seq[i];
        if (number > b) continue;
        for (int j = 0; j <= b; j++) {
            if (sums[j] == 1 && j + number <= b) {
                sums[j + number] = 1;
            }
        }
        sums[number] = 1;
    }
}

int main() {
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }
    solve(a, b);
    cout << getSize();
    return 0;
}