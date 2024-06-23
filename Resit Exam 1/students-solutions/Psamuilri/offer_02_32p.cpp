#include <cmath>
#include <climits>
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::vector<int> itemsPrices;
    std::cin >> n >> k;
    int sum=0;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        sum = sum+j;
        itemsPrices.push_back(j);
    }
    std::sort(itemsPrices.begin(), itemsPrices.end());
    int jumper = n-k;
    //cout << sum<<endl;
    while (jumper > k) {
        //cout << "jump:" << jumper << " "<<"itemsPrices[jumper]:"<< itemsPrices[jumper]<<endl;
        sum = sum - itemsPrices[jumper];
        jumper =jumper - k;
    }
    sum = sum - itemsPrices[0];
    cout << sum;
}
