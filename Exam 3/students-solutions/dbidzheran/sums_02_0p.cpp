//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <iomanip>
using namespace std;

int n, a, b;
vector<int> nums;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> a >> b;

    for (int i = 0; i < n; ++i)
    {
        nums.push_back(0);
        cin >> nums[i];
    }
    
    sort(nums.begin(), nums.end());
    vector<int> prevSum(n, 0);
    vector<int> sums(n, 0);

    prevSum[0] = nums[0];
    if (nums[0] >= a && nums[0] <= b)
    {
        ++sums[0];
    }
    for (int j = 1; j < n; ++j)
    {
        prevSum[j] = prevSum[j-1] + nums[j];
        sums[j] = sums[j - 1];
        for (int k = 0; k < j; ++k)
        {
            if (prevSum[k] + nums[j] >= a && prevSum[k] + nums[j] <= b)
            {
                ++sums[j];
            }
        }

        if(nums[j] >= a && nums[j] <= b && nums[j - 1] != nums[j])
        {
            ++sums[j];
        }
    }

    cout << sums[n-1] << '\n';
}

/*
7 3 6
10 8 2 3 10 5 5

*/