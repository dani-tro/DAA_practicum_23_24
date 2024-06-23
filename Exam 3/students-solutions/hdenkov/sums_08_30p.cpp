#include <bits/stdc++.h>
using namespace std;

#define MAX 128
#define endl '\n'

int n, a, b;
vector<int> nums;

int dp[MAX];

unordered_set<int> legitS;
unordered_set<int> s;
vector<int> currSums;

void printSet()
{
    for (int sum : legitS)
    {
        cout << sum << ' ';
    }
    cout << endl;
}

int calc(int curr)
{
    // if (curr >= a && curr <= b)
    //     currSums.push_back(curr);

    unordered_set<int> s1(s);
    s.insert(curr);

    for (int sum : s1)
    {
        int currSum = sum + curr;
        currSums.push_back(currSum);
    }

    // cout << "curr sums: " << endl;

    // for (int sum : currSums)
    // {
    //     cout << sum << ' ';
    // }
    // cout << "______" << endl;

    for (int sum : currSums)
    {
        s.insert(sum);
        if (sum >= a && sum <= b)
            legitS.insert(sum);
    }

    // printSet();

    return legitS.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> a >> b;
    int i, k;
    for (i = 0; i < n; ++i)
    {
        cin >> k;
        if (k <= b)
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