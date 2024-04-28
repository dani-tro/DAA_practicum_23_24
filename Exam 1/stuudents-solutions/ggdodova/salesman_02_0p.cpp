#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

bool greaterThan(std::pair<double, double> one, std::pair<double, double> two){
    return one.second > two.second;
}
int main() {
    //std::ios_base::sync_with_stdio(false);
    //std::cin.tie(NULL);
    int m;
    int n;
    std::cin>>m>>n;
    std::vector<std::pair<float, float> >nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin>>nums[i].first;
        std::cin>>nums[i].second;
    }
    double s=0; //max value in leva that is allowed
    std::vector<double> c(n);
    std::sort(nums.begin(), nums.end(), greaterThan);
    long kiloSum=0;
    int count=0;
    while(count<n) {
         kiloSum+=nums[count].first;
       if(kiloSum<m){
            s+= nums[count].first * nums[count].second;
            c[count]=nums[count].first;
        } else {
           count++;
       }
    }

        std::cout << std::fixed << std::setprecision(2) << s << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cout << std::fixed << std::setprecision(3) << c[i] << std::endl;
        }

    return 0;
}
