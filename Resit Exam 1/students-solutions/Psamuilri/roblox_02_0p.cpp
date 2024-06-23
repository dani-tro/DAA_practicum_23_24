#include <cmath>
#include <climits>
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

std::vector<int> boxer;

int joy(int beg,int end,int extasy) {
    int totalJoy = 0;
    for (int i = beg; i < end; i++) {
        for (int j = i + 1; j <= end; j++) {
            int currJoy=boxer[i] * boxer[j];
            totalJoy = totalJoy + currJoy;
        }
    }
    //cout << totalJoy<<" ";
    if (totalJoy >= extasy) { return 1; }
    return 0;

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, k;
    
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        boxer.push_back(j);
    }
    std::sort(boxer.begin(), boxer.end());
    for (int i = 0; i < boxer.size(); i++) {
        cout << boxer[i] << " ";
    }
    int allPossibleIntervals=0;
    for (int interval = 1; interval <= n; interval++) {
        for (int start = 0; start < n - interval; start++) {
            int end = start + interval;
            if (joy(start, end, k)) { allPossibleIntervals = allPossibleIntervals + n - end; break; }
            
        }
    }
    cout << allPossibleIntervals;
    return 0;
}