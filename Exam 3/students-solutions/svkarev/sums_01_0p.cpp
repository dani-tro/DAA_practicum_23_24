#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint32_t n,a,b;

    cin >> n >> a >>b;

    vector<uint32_t> inp(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> inp[i];
    }
    sort(inp.begin(), inp.end());
    vector<vector<int>> dp(n, vector<int>(b+1, 0));

    if(inp[0] <= b)
        dp[0][inp[0]]++;
    

    for (size_t num = 1; num < n; num++)
    {
        for (size_t s = 1; s <= b; s++)
        {
            if(dp[num-1][s] != 0)
            {
                if(inp[num-1] + inp[num] <= b)
                    dp[num][inp[num-1] + inp[num]]++;  
                
                dp[num][s]++;
            }
        }
        if(inp[num] <= b)
            dp[num][inp[num]]++;
    }
    
    uint32_t cnt = 0;
    for (size_t i = a; i <= b; i++)
    {
        if(dp[n-1][i] != 0)
            cnt++;
    }
    cout << cnt << endl;

    // for (size_t i = 0; i < n; i++)
    // {
    //     cout << setw(2) << inp[i] <<": ";
    //     for (size_t j = 1; j <= b; j++)
    //     {
    //         cout << setw(4)<< dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    

    

    return 0;
}

/*
7 3 6
10 8 2 3 10 5 5

    1 2 3 4 5 6
10
8
2
3
10
5
5

*/