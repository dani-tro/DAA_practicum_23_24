#include <cmath>
#include <climits>
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

std::vector<int> boxer;

int joy(int beg, int end, long long extasy) {
    long long totalJoy = 0;
    for (int i = beg; i < end; i++) {
        for (int j = i + 1; j <= end; j++) {
            long long currJoy = boxer[i] * boxer[j];
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
    int n;
    long long k;

    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        boxer.push_back(j);
    }
    long long allPossibleIntervals = 0;

    for (int start = 0; start < n - 1; start++) {
        for (int interval = start; interval < n; interval++) {
            int end = interval;
            if (joy(start, end, k)) { allPossibleIntervals = allPossibleIntervals + n - interval; break; }
        }
    }
    cout << allPossibleIntervals;
    return 0;
}
