#include<bits/stdc++.h>
const int MAX= 10e5;
int arr[MAX];
int n, k;
int main(){
    std::ios_base :: sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> k;
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    std::sort(arr, arr  + n);
    int left;
    int right;
    int cut = 0;
    int answer = - 1;
    for(int i = 0; i < n; i++){
        cut = arr[i];
        left = i + 1;
        right = n - 1;
        while(left <= right){
            int middle = left + (right - left)/2;
            int current = arr[middle] - cut;
           // std::cout << current << ' ' << i  << ' ' << middle << std::endl;
            if(current <= k){
                answer = std::max(answer, middle - i);
                left = middle + 1;
                
            }
            else{
                right = middle - 1;
            }
        }
    }
    std::cout << answer + 1;

    return 0;
}