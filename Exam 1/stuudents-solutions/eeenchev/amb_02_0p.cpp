#include<iostream>
const int MAX = 10e5 + 1;
int k, n;
int arr[MAX];
int answer = 1000000001;
bool check(int input){
    int cut = 0;
    int tvs = k;
    //std::cout << input << std::endl;
    while(tvs > 0 && cut < n - 1){
        int left = cut;
        int right = n - 1;
        int current = arr[cut];
        int last_success = -1;
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
           // std::cout << "as" << std::endl;
            return false;
        }else{
            //std::cout << "sa" << std::endl;
            cut = last_success + 1;
            tvs--;
        }
    }
    if(cut >= n - 1){
        //std::cout << "hi" << std::endl;
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
        int temp;
        std::cin >> temp;
        arr[i] = arr[i - 1] + temp;
    }
    int left = 0;
    int right = arr[n - 1];
    while(left <= right){
        int middle = left + (right - left) / 2;
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