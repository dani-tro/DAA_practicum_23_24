#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
//#include<bits/stdc++.h>
//cZQ4w3j3PyGV
const long long MOD = 1000000007;
long long n, i, j, k, s;
long long dp_up[201][201][201];
long long dp_down[201][201][201];
long long sums[2001], temp_u, temp_d;
long long answer = 0;
int main(){
    std::ios_base :: sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    for(i = 1; i <= n; i++){
        for(k = 1; k <= n; k++){
            dp_up[0][i][k] = 1 + dp_up[0][i][k - 1];
            dp_down[0][i][k] = 1 + dp_down[0][i][k - 1];
            sums[i] = 1;
        }
    }
    for(i = 1; i <= n; i++){
        if(i % 2 == 1){//up for dp_up, down for dp_down
            // dp_up[i][1] = 0;
            // dp_down[i][1] = 0;
             for(j = 1; j <= n; j++){
                for(k = j; k <= n; k++){
                    // temp_u = (dp_up[i][j] + dp_up[i - 1][j - 1] - dp_up[i - 1][j - 2] + dp_up[i][j - 1]) % MOD;
                    // temp_d = ( dp_down[i][j] + dp_down[i - 1][n] - dp_down[i - 1][j] + dp_down[i][j - 1] ) % MOD;
                    dp_up[i][j][k] = (dp_up[i - 1][j - 1][k - j] - dp_up[i - 1][j - 2][k - j] + dp_up[i][j - 1][k]) % MOD;
                    dp_down[i][j][k] = (dp_down[i - 1][n][k - j] - dp_down[i - 1][j][k - j] + dp_down[i][j - 1][k] ) % MOD;
                 }
                 
                 
                 //dp_up[i][j] = (dp_up[i][j] +dp_up[i - 1][j - 1] - dp_up[i - 1][j - 2] + dp_up[i][j - 1]) % MOD;
                 //dp_down[i][j] = ( dp_down[i][j] + dp_down[i - 1][n] - dp_down[i - 1][j] + dp_down[i][j - 1] ) % MOD;
                //dp_up[i][j] += dp_up[i - 1][j - 1] + dp_up[i][j - 1];
            }
        }else{
            for(j = 2; j <= n; j++){// check j = 1
                // for(k = j + 1; k <= n; k++){
                //     dp_up[i][k] += dp_up[i - 1][k] - dp_up[i][j];
                // }
                for(k = j; k <= n; k++){
                    dp_up[i][j][k] = (dp_up[i - 1][n][k - j] - dp_up[i - 1][j][k - j] + dp_up[i][j - 1][k]) % MOD;
                    dp_down[i][j][k] = (dp_down[i - 1][j - 1][k - j] - dp_down[i - 1][ j - 2][ k - j] + dp_down[i][j - 1][k]) % MOD;
                }
                
                
            }
           
            
        }
    }
    // for(i = 0; i <= n; i++){
    //     std::cout << dp_up[i][n] << ' ' << dp_down[i][n] << std::endl;
    // }
    for(i = n - 1; i >= 1; i--){
        answer = (answer + dp_down[i][n][n] + dp_up[i][n][n]) % MOD;
    }
    std::cout << answer;
    // std::cout << dp_up[n][n][n] + dp_down[n][n][n];
    return 0;
}