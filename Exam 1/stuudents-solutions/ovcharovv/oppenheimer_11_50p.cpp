#include <iostream>
#include<algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    long n, k;
    long s;
    std::cin >> n >> k;
    long* arr = new long[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::sort(arr, arr + n);
    int max = 0;
    //5 9 3 1 2 7 8 9 5 8
    //1 2 3 5 5 7 8 8 9 9
    int r = n - 1;
    int l = 0;
    int init = 1;
    while (true) {
        if (arr[r] - arr[l] <= k) {
            std::cout<< r - l + 1;
            break;
        }
        else if(r!=n-1){
            l++;
            r++;
        }
        else if (r == n - 1) {
            l = 0;
            r = n - (++init);
            if (l >= r) {
                std::cout << 0;
                break;
            }
        }
        
    }
}