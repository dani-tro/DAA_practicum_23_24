#include<iostream>
const int MAXN = 1e7 + 2;
long long n, k, current;
int i, j;
//long long thrill[MAXN];
long long temp[MAXN];
int nums[MAXN];
long long prod[MAXN];
//long long another[MAXN];
long long count = 0;
int main(){
    std::cin >> n >> k;
    std::cin >> nums[0];
    //thrill[0] = 0;
    for(i = 1; i < n; i++){
        std::cin >> nums[i];
        //thrill[i] += thrill[i - 1];
        for(j = i - 1; j >= 0; j--){
            prod[i] += nums[j] * nums[i];
            //another[j] = prod[i];
            temp[j] = prod[j];
            if(temp[j] >= k){
                count++;
            }
        }
        //thrill[i] += prod[i];
        // if(thrill[i] >= k){
        //     count++;
        // }
    }
    // for(i = 1; i <= n - 1; i++){
    //     if(thrill[i + j] > k){
    //         count++;
    //     }
    //     for(j = 1; j <= n - i; j++){
    //         if(thrill[j + i] - thrill[i - 1]){

    //         }
    //     }
    // }
    std::cout << count;
    return 0;
}