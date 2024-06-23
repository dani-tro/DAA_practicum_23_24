#include <cmath>
#include <climits>
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int const MAX = 999999;
std::vector<int> nums;
std::vector<int> vec;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int all = 0;
    for (int i = 0; i < n; i++) {
        short num;
        cin >> num;
        nums.push_back(num);
    }

    for (int i = 1; i < nums.size(); i++) {
        

        for (int j = 0; j < vec.size();j++) {
            if (nums[i] + j < a) {
                int k = nums[i] + vec[j];
                vec.push_back(k);
            }
            if ((nums[i] + vec[j] > a) && (nums[i] + vec[j] < b)) {
                int k = nums[i] + vec[j];
                vec.push_back(k);
                
            }
        }
        int p = nums[i];
        vec.push_back(p);
    }
    std::sort(vec.begin(),vec.end());
    //std::unique(vec.begin(), vec.end());
    if (vec[0] > a && vec[0] < b)all++;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] >= a) {
            if (vec[i] <= b) {
                if (vec[i] != vec[i - 1]) { all++; }
            }
            else { break; }

        }
    }
    
    
    cout << all;
}
