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
    //vector<vector<int>> sums(n, vector<int>(n, 0));

    if (nums[0] >= a && nums[0] <= b)
    {
        prevSum[0] = nums[0];
        ++sums[0];
    }
    for (int j = 1; j < n; ++j)
    {
        if (prevSum[j] + nums[j] >= a && prevSum[j] + nums[j] <= b)
        {
            prevSum[j] = prevSum[j] + nums[j];
            if(nums[j-1] != nums[j])
            {
                sums[j] = sums[j - 1] + 1;
            }
            else
            {
                sums[j] = sums[j - 1];
            }
        }
        else
        {
            sums[j] = sums[j - 1];
        }
    }

    /*int answer = 0;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (i == j && nums[j] <= b && nums[j] >= a)
            {
                ++sums[i][j];
            }
            else
            {
                sums[i][j] = max(sums[i - 1][j], sums[i - 1][j - 1]);
            }
            if (sums[i][j] > answer)
            {
                answer = sums[i][j];
            }
        }
    }*/

    cout << sums[n-1] << '\n';
}

/*
7 3 6
10 8 2 3 10 5 5

*/