#include<iostream>
const int MAXN = (1e7 + 4) / 2;
long long n, k, current;
int i, j;
long long temp[MAXN];
int nums[MAXN];
long long prod[MAXN];
// long long another[MAXN];
long long count = 0;
int main(){
    std::cin >> n >> k;
    std::cin >> nums[0];
    for(i = 1; i < n; i++){
        std::cin >> nums[i];
        for(j = i - 1; j >= 0; j--){
            prod[i] += nums[j] * nums[i];
            // another[j] = prod[i];
            temp[j] += prod[i];
            if(temp[j] >= k){
                count+= j + 1;
                break;
            }
        }
      
    }
    
    std::cout << count;
    return 0;
}