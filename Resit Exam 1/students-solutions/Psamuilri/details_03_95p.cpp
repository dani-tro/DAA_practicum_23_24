#include <cmath>
#include <climits>
#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;
int const MAX = 100005;
//std::pair<int, int> pairs;
std::vector<std::vector<int>> vecPairs;

int binSearch(int totalDNo, int totalDYes, int p) {
    if (totalDNo + 1 >= totalDYes) return totalDYes;
    int sum = 0;
    int mid = (totalDYes + totalDNo) / 2;
    for (int i = 0; i < vecPairs.size(); i++) {
        if (vecPairs[i][0] < mid) {
            sum += (mid - vecPairs[i][0]) / vecPairs[i][1];
        }

    }
    //std::cout << totalDYes << " "<<totalDNo<<" "<<sum<<endl;
    if (sum < p) { return binSearch(mid, totalDYes, p); }
    if (sum >= p) { return binSearch(totalDNo, mid, p); }

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int sum = 0;
    int totalD = 1;

    int n, p;
    cin >> n >> p;

    for (int i = 0; i < n; i++) {
        int k, k1;
        cin >> k >> k1;
        std::vector<int> vec;
        vec.push_back(k1);
        vec.push_back(k);
        vecPairs.push_back(vec);
    }
    //cout << vecPairs.size()<<endl;
    while (sum < p) {
        for (int i = 0; i < vecPairs.size(); i++) {
            if(vecPairs[i][0]<totalD){
                sum += (totalD - vecPairs[i][0]) / vecPairs[i][1];
                //cout << sum<<" ";
            }

        }
        if (sum < p) { sum = 0; }
        totalD=totalD*2;
    }
    //cout << endl;
    int totalDYes = totalD;
    int totalDNo = totalD / 4;
    //std::cout << "WWW";
    std::cout << binSearch(totalDNo, totalDYes, p);



    return 0;
}