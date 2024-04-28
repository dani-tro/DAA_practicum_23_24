#include <bits/stdc++.h>

const int MAX_SIZE = 1e5;
long long arr[MAX_SIZE];
int n, k;
int count, maxCount;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin>>n>>k;

    for (size_t i = 0; i < n; i++) {
        std::cin>>arr[i];
    }
    
    std::sort(arr,arr+n);

    int first = arr[0];
    int firstIndex = 0;
    count = 1;
    for (size_t i = 1; i < n; i++) {
        if(arr[i] - first > k) {
            count--;
            firstIndex++;
            first = arr[firstIndex];
            i--;
        } else {
            count++;
        }

        if(maxCount < count) maxCount = count;
    }

    std::cout<<maxCount<<std::endl;
}