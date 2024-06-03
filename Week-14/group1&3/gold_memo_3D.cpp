#include <bits/stdc++.h>

using namespace std;

#define MAX 52

int n, a[MAX], dp[MAX][50001][50001];

int rec(int idx, int delta, int thrown)
{
    if(idx == n + 1)
    {
        if(delta == 0)
        {
            return thrown;
        }
        return INT_MAX / 2;
    }	
    
    if(dp[idx][delta][thrown])return dp[idx][delta][thrown];
    
    int ans = INT_MAX / 2;
    ans = min(ans, rec(idx + 1, delta + a[idx], thrown));
    ans = min(ans, rec(idx + 1, delta - a[idx], thrown));
    ans = min(ans, rec(idx + 1, delta, thrown + a[idx]));
    
    return dp[idx][delta][thrown] = ans;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    
    cout << rec(1, 0, 0) << endl;
    
    return 0;
}

