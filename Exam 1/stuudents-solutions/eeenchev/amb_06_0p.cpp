#include<iostream>
const int MAX = 10e5 + 1;
const int sth = 10e18;
int k, n;
long long arr[MAX];
long long answer = sth;
bool check(long long input){
    int cut = 0;
    int tvs = k;
    int left;
    int last_success;
    //std::cout << input << std::endl;
    while(tvs > 0 && cut < n - 1){
        left = cut;
        int right = n - 1;
        long long current = arr[cut];
        last_success = -1;
        while(left <= right){
            //std::cout << "ar" << std::endl;
            int middle = left + (right - left) / 2;
            //std::cout << arr[middle] << ' ' << current << ' ' << input << std::endl;
            if(arr[middle] - current <= input){
                last_success = middle;
                left = middle + 1;
            }else{
                right = middle - 1;
            }
        }
        if(last_success == -1){
            return false;
        }else{
            cut = last_success;
            tvs--;
        }
    }
    if(cut >= n - 1){
        return true;
    }
    return false;
}

int main(){
    std::ios_base :: sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin >> n >> k;
    arr[0] = 0;
    for(int i = 1; i < n; i++){
        long long temp;
        std::cin >> temp;
        arr[i] = arr[i - 1] + temp;
    }
    long long left = 0;
    long long right = arr[n - 1];
    while(left <= right){
        long long middle = left + (right - left) / 2;
        if(check(middle)){
            answer = middle;
            right = middle - 1;
        }else{
            left = middle + 1;
        }
    }
    std::cout << answer;
    return 0;
}