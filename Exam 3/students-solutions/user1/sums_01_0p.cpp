#include <bits/stdc++.h>
#define MAXN 100010
#define MAXK 1010
using namespace std;

int n, k;
int moves[MAXK];
int board[MAXN];
bool used[MAXN];
int dp[MAXN][MAXN];

long long calc(int a, int b) {
    if(a >= b) return 0;

    long long m = 0;

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            if(a + moves[i] >= b || b - moves[j] <= a) break;
            if(i == 0 && j == 0) continue;

            long long f = calc(a + moves[i], b - moves[j]);
            if(!used[a]) f += board[a];
            if(!used[b]) f += board[b];
            
            cout << a + moves[i] << " - " << b - moves[j] << "   " << f << endl; 
            if(f > m) {
                m = f;
                used[a] = true;
                used[b] = true;
            }

        }
    }

    return m;
}

int main() {

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> board[i];
    }

    for(int i = 1; i <= k; i++) {
        cin >> moves[i];
    }

    cout << calc(1, n);

    return 0;
}