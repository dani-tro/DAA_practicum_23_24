#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
//#include<bits/stdc++.h>
//cZQ4w3j3PyGV
const long long MOD = 1000000007;
int n, i, j, k, s;
long long dp_up[2001][2001];
long long dp_down[2001][2001];
long long sums[2001];
int main(){
    std::ios_base :: sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    for(i = 1; i <= n; i++){
        dp_up[0][i] = i;
        dp_down[0][i] = i;
        sums[i] = 1;
    }
    for(i = 1; i <= n; i++){
        if(i % 2 == 1){//up for dp_up, down for dp_down
            // dp_up[i][1] = 0;
            // dp_down[i][1] = 0;
             for(j = 2; j <= n; j++){
                 dp_up[i][j] = (dp_up[i][j] +dp_up[i - 1][j - 1] - dp_up[i - 1][j - 2] + dp_up[i][j - 1]) % MOD;
                 dp_down[i][j] = ( dp_down[i][j] + dp_down[i - 1][n] - dp_down[i - 1][j] + dp_down[i][j - 1] ) % MOD;
                //dp_up[i][j] += dp_up[i - 1][j - 1] + dp_up[i][j - 1];
            }
        }else{
            for(j = 2; j <= n; j++){// check j = 1
                // for(k = j + 1; k <= n; k++){
                //     dp_up[i][k] += dp_up[i - 1][k] - dp_up[i][j];
                // }
                dp_up[i][j] = (dp_up[i][j] + dp_up[i - 1][n] - dp_up[i - 1][j] + dp_up[i][j - 1]) % MOD;
                dp_down[i][j] = (dp_down[i][j] +dp_down[i - 1][j - 1] - dp_down[i - 1][ j - 1] + dp_down[i][j - 1]) % MOD;
                
            }
           
            
        }
    }
    // for(i = 0; i <= n; i++){
    //     std::cout << dp_up[i][n] << ' ' << dp_down[i][n] << std::endl;
    // }
    std::cout << dp_up[n][n] + dp_down[n][n];
    return 0;
}