#include <bits/stdc++.h>

using namespace std;

#define MAX 5010

long long n, k, f, a, b, m, x, pr[MAX][MAX], opt = -1;

long long sum(int i, int j, int len)
{
    return pr[i + len - 1][j + len - 1] - pr[i - 1][j + len - 1] - pr[i + len - 1][j - 1] + pr[i - 1][j - 1];
}

bool calc(int m)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i + m - 1 > n)continue;
            if(j + m - 1 > n)continue;
            if(sum(i, j, m) < k)return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
    	cin >> f >> a >> b >> m;
        for(int j = 1; j <= n; j++)
        {
            if(j == 1) x = f;
            else x = (x * a + b) % m;
            pr[i][j] = pr[i - 1][j] + pr[i][j - 1] - pr[i - 1][j - 1] + x;
        }
    }
    
    int l = 1, r = n, mid;
    
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(calc(mid) == true)
        {
            r = mid - 1;
            opt = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    
    cout << opt << endl;
    
    return 0;
}

