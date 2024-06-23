#include <bits/stdc++.h>

#define MAX 100000

using namespace std;

int n, p, day = 0;
int produced = 0;
int days[MAX][2];

int solve() {
    while (produced != p) {
        for (int i = 0; i < n; i++) {
            if (days[i][0] >= day) continue;
            int work_days = (day - days[i][1]);
            if (work_days > 0 && work_days % days[i][0] == 0) produced++;
            if (produced == p) return day;
        }
        day++;
    }
    return day;
}

int main() {
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> days[i][0] >> days[i][1];
        day = min(day, days[i][1]);
    }

    cout << solve();
}