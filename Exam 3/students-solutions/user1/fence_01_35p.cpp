#include <bits/stdc++.h>
#define MAXN 2010
using namespace std;

int s;
//tall/short ; number of bricks ; last col
long long dp[2][MAXN][MAXN];

void calc() {

    for(int i = 0; i < 2; i++) {
        dp[i][1][1] = 1;
        for(int j = 0; j <= s; j++) {
            dp[i][j][j] = 1;
        }

        for(int k = 0; k <= s; k++) {
            dp[i][0][k] = 1;
        }

    }

    for(int j = 1; j <= s; j++) {
        for(int k = 1; k < j; k++) {
            for(int i = 0; i < 2; i++) {
                if(i == 1) 
                    for(int m = 1; m <= k - 1; m++) dp[i][j][k] += dp[(i + 1) % 2][j - k][m];
                else 
                    for(int m = k + 1; m <= j - k; m++) dp[i][j][k] += dp[(i + 1) % 2][j - k][m];
            }
        }
    }

}

int main() {

    cin >> s;

    long long ans = 0;

    calc();

    for(int i = 0; i < 2; i++) {
        for(int k = 1; k < s; k++) {
            ans += dp[i][s][k];
        }
    }

    // for(int i = 0; i < 2; i++) {
    //     for(int j = 1; j <= s; j++) {
    //         for(int k = 1; k <= j; k++) {
    //             cout << ((i == 1)? "tall ; ": "short ; ") 
    //                 << "num. bricks: " << j << " ; " 
    //                 << "last was " << k << "   " << dp[i][j][k] << endl;
    //         }
    //     }
    // }

    cout << ans + 1;

    return 0;
}