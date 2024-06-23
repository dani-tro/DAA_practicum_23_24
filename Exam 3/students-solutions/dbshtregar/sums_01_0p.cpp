#include<bits/stdc++.h>
using namespace std;
#define MAXN 101
int n, a, b, ans = 0;
int arr[MAXN];
int dp[MAXN][MAXN];
int func(int a, int b)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(dp[i][j] >= a && dp[i][j] <= b && dp[i][j] != dp[i][j-1])
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>a>>b;
    for(int i = 0; i < n; i++)
    {
        cin>>dp[0][i];
    }


    cout<<func(a, b)<<endl;
    return 0;
}
