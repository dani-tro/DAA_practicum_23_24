#include<iostream>

short n, a, b, i, j, count = 0;
short num;
bool dp[101][101];
bool answers_seen[101];
int main(){
    std::cin >> n >> a >> b;
    std::cin >> num;
    dp[0][0] = true;
    dp[0][num] = true;
    for(i = 1; i < n; i++){
        std::cin >> num;
        for(j = 0; j <= 100; j++){
            dp[i][j] = dp[i - 1][j] || (num <= j && dp[i - 1][j - num]);
            if(dp[i][j]){
                answers_seen[j] = true;
            }
        }
    }
    for(i = a; i <= b; i++){
        count += answers_seen[i];
    }
    std::cout << count;
    return 0;
}