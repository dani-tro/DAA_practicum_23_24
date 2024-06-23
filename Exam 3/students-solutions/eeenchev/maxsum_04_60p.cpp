#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
//#include<bits/stdc++.h>
const int MAXN = 1e5 + 2;
const int MAXM = 1e3 + 2;
const long long INF = -(1e17 * 2);
int n, k, i, j;
int nums[MAXN];
long long dp_left[MAXN];
long long dp_right[MAXN];
short pos[MAXM];
long long maxm = INF;
long long interim[MAXN][2];
int position;
int main(){
    std::ios_base :: sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> k;
    for(i = 0; i < n; i++){
        std::cin >> nums[i];
        dp_left[i] = INF;
        dp_right[i] = INF;
    }
    for(i = 0; i < k; i++){
        std::cin >> pos[i];
    }
    dp_left[0] = nums[0];
    interim[0][0] = nums[0];
    dp_right[n - 1] = nums[n - 1];
    interim[n - 1][1] = nums[n - 1];

    for(i = 0; i <= n -1; i++){
        for(j = 0; j < k; j++){
            position = i - pos[j];
            if(position >= 0 && dp_left[position] != INF){
                dp_left[i] = std::max(dp_left[i], dp_left[position] + nums[i]);
                interim[i][0] = std::max(dp_left[i], interim[i][0]);
            }
            position = n - 1 - i + pos[j];
            if(position <= n -1 && dp_right[position] != INF){
                dp_right[(n - 1 - i)] = std::max(dp_right[((n - 1 - i))], dp_right[position] + nums[(n - 1 - i)]);
                interim[n - 1 - i][1] = std::max(dp_right[n - 1 - i], interim[n - 1 - i][1]);
            }
        }
    }
    // for(i = 0; i <= n - 2; i++){
    //     for(j = i + 1; j <= n - 1; j++){
    //         maxm = std::max(maxm, dp_left[i] + dp_right[j]);
    //     }
    // }
    for(i = 0; i <= n - 2; i++){
        maxm = std::max(maxm, interim[i][0] + interim[i + 1][1]);
    }

    std::cout << maxm;
    return 0;
}