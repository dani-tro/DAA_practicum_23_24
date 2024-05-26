/**
2018 Sofia autumn tournament in informatics
Task  : platforms
Group : D
Author: Desislava Ratcheva
*/
#include<bits/stdc++.h>
using namespace std;

int table[1001][1001];

int main() {
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> table[i][j];

            if (table[i][j] != table[i][j-1] && table[i][j] != table[i-1][j]) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
