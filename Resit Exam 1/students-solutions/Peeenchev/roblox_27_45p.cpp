#include<iostream>
#include<queue>
const int MAXN = (1e7 + 4) / 2;
long long n, k, current = 0, nz = -1;
int i, j, prev2, cur1, cur2;
long long temp[MAXN];
bool prev1 = false;
int nums[MAXN];
long long prod[MAXN];
// long long another[MAXN];
long long count = 0;
int main(){
    std::cin >> n >> k;
    std::cin >> nums[0];
    if(k == 1 && n > 5000){
        temp[0] = 0;
        for(i = 1; i < n; i++){
            std::cin >> nums[i];
            temp[i] = temp[i - 1] + i;
        }
        count = temp[n - 1];
        for(i = 0; i <= n - 1;i++){
            // std::cin >> nums[i];
            // temp[i] += temp[i - 1] + i;
            if(nums[i] == 0){
                nz++;
            }else{
                if(prev1){
                    count = count - temp[nz];
                    nz = 0;
                }else{
                    prev1 = true;
                    nz++;
                }
            }
        }
    }else{
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
    }
    std::cout << count;
    return 0;
}