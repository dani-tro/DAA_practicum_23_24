#include <bits/stdc++.h>
using namespace std;
const int SIZE = 105;
int arr[SIZE];
int dp [SIZE][SIZE];
int n,a,b;
set<int> s;
int main() {
    #define endl '\n'
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> a >> b;
    for (size_t i = 1; i <= n; i++) {
        int d;
        cin >> d;
        arr[i] = d;
        dp[d][d] = 1;
    }
    for (int i = 1; i <= 100; i++) {
        for (int j = i +1 ; j <=100 ; j++) {
            int c = 0;
            for (int k = 1; k <= n; k++) {
               if (j - arr[k] >=0) {
                c = dp[(i - arr[k] >=0 ? i - arr[k] : 0)][j - arr[k]] + 1;
               } 
            }
            dp[i][j] = c + dp[i][j-1];
            
        }
        
    }
    cout << dp[1][3];
    
}