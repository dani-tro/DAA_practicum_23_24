#include <cmath>
#include <climits>
#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;
int const MAX = 100005;
//std::pair<int, int> pairs;
std::vector<std::vector<int>> vecPairs;

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
        totalD++;
    }
    //cout << endl;
    cout << totalD-1;



    return 0;
}
