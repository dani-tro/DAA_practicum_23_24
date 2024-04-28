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
    for (int i = 0; i < n; i++)
    {
        
        for (int j = n-1; j >= 0; j--)
        {
            if (arr[j] - arr[i] <= k) {
                if (max < j - i + 1) {
                    max = j - i + 1;
                    if (max > n - i - 1) {
                        std::cout << max;
                    }  
                }
                break;
            }
        }
    }
    std::cout << max;
}