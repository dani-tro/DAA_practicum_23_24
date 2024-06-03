#include <bits/stdc++.h>

using namespace std;

#define MAX 210000

int n, a, b, dp[MAX][2];

vector<int> gr[MAX];

int dfs(int node, bool flag, int par)
{
	if(dp[node][flag] != -1)return dp[node][flag];
	dp[node][flag] = 0;
	if(flag == 0)
	{
		for(int u : gr[node])
		{
			if(u != par)
			{
				dp[node][flag] += max(dfs(u, 0, node), dfs(u, 1, node)); 
			}
		}
		
	}
	else
	{
		for(int u : gr[node])
		{
			if(u != par)
			{
				dp[node][flag] = max(dp[node][flag], 1 + dfs(u, 0, node) + 
													dfs(node, 0, par) - max(dfs(u, 0, node), dfs(u, 1, node)));
			}
		}
	}
	return dp[node][flag];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin >> n;
    
    for(int i = 0; i <= n; i++)dp[i][0] = dp[i][1] = -1;
    
    for(int i = 0; i < n - 1; i++)
    {
    	cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	
	cout << max(dfs(1, 0, 0), dfs(1, 1, 0)) << endl;
    
    return 0;
}

