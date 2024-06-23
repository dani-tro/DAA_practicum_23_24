#include <bits/stdc++.h>

using namespace std;

#define MAX 5010

long long n, k, f, a, b, m, x, pr[MAX][MAX], ans = 1;

long long sum(int i, int j, int len)
{
    return pr[i + len - 1][j + len - 1] - pr[i - 1][j + len - 1] - pr[i + len - 1][j - 1] + pr[i - 1][j - 1];
}

bool check(int m)
{
    for(int i = n - m; i >= 1; i--)
    {
        for(int j = n - m; j >= 1; j--)
        {
            if(i + ans - 1 > n)continue;
            if(j + ans - 1 > n)continue;
            if(sum(i, j, ans) < k)return false;
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
    	x = f;
    	for(int j = 1; j <= n; j++)
        {
            if(j > 1) x = (x * a + b) % m;
            pr[i][j] = pr[i - 1][j] + pr[i][j - 1] - pr[i - 1][j - 1] + x;
        }
    }
    
    for(ans = 1; ans <= n; ans++)
    {
        if(check(ans))break;
    }
    
    if(sum(1, 1, ans) < k)ans = -1;
    cout << ans << endl;
    
    return 0;
}

