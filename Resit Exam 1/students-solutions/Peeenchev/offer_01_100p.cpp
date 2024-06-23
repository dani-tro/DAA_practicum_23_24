#include<iostream>
#include<algorithm>
const int MAXN = 1e5 + 2;
int n, k, i, j;
long long sum = 0;
int nums[MAXN];
int main(){
    std::cin >> n >> k;
    for(i = 0; i < n; i++){
        std::cin >> nums[i];
        sum += nums[i];
    }
    std::sort(nums, nums + n);
    for(j = n - k; j >= 0; j-=k){
        sum -= nums[j];
    }
    std::cout << sum;
    return 0;
}