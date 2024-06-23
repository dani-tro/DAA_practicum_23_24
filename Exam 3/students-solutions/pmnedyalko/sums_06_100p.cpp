#include <bits/stdc++.h>

const int MAX_SUM = 1e4 + 100;
const int MAX_SIZE = 128;
int arr[MAX_SIZE];
bool used[MAX_SUM];
std::vector<int> sums;
int n,a,b;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin>>n>>a>>b;
    for (int i = 1; i <= n; i++) {
        std::cin>>arr[i];
    }

    for (int i = 1; i <= n; i++) {
        int sizeV = sums.size();
        for (size_t j = 0; j < sizeV; j++) {
            if(!used[sums[j] + arr[i]]) {
                sums.push_back(sums[j] + arr[i]);
                used[sums[j] + arr[i]] = true;
            }
        }

        if(!used[arr[i]]) {
            sums.push_back(arr[i]);
            used[arr[i]] = true;
        }
    }
    
    int ans = 0;
    for(int sum : sums) {
        if(sum >= a && sum <= b) {
            ans++;
        }
    }

    std::cout<<ans<<std::endl;
    return 0;
}