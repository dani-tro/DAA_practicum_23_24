#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin.tie(NULL); std::cout.tie(NULL);
     int N, A, B;
     std::cin>>N>>A>>B;

     std::vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        std::cin>>nums[i];
    }
    int cnt=0;

      int sum=0;
    for (int i = 0; i < N; ++i) {
       if(nums[i]>B){
           i++;
       }else{
           sum+=nums[i];
       }
      if(sum>=A && sum<=B){
          cnt++;
      }
    }


    std::cout<<cnt;

    return 0;
}
