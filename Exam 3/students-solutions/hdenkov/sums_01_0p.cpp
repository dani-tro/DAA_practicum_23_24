#include <bits/stdc++.h>
using namespace std;

#define MAX 128

int n, a, b;
vector<int> nums;

int dp[MAX];
unordered_set<int> s;

void printSet()
{
    for (int sum : s)
    {
        cout << sum << ' ';
    }
    cout << endl;
}

int calc(int curr)
{
    vector<int> currSums;
    if (curr >= a)
        s.insert(curr);

    for (int sum : s)
    {
        int currSum = sum + curr;
        if (currSum >= a && currSum <= b)
            currSums.push_back(currSum);
    }

    // for (int sum : currSums) {
    //     cout << sum << ' ';
    // }
    // cout << endl;

    for (int sum : currSums)
    {
        currSums.push_back(sum);
    }

    return s.size();
}

int main()
{
    cin >> n >> a >> b;
    int i, k;
    for (i = 0; i < n; ++i)
    {
        cin >> k;
        if (k < b)
        {
            nums.push_back(k);
        }
    }

    for (i = 0; i < nums.size(); ++i)
    {
        calc(nums[i]);
    }

    cout << calc(nums.size() - 1) << endl;
}