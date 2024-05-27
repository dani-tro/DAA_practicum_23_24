#include <bits/stdc++.h>

using namespace std;

#define MAX 2048

long long m, n, dp[MAX][MAX];

string a, b;

int main()
{
    cin >> a;
    cin >> b;
    
	n = a.size();
	m = b.size();
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
    
    cout << dp[n][m] << endl;
    
    return 0;
}

