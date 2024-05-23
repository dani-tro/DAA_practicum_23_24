#include <bits/stdc++.h>

using namespace std;

#define MAX 510000

string s;

int n, in[MAX], br = 1, ans[MAX];

vector<int> gr[MAX];

void topoSort()
{
	priority_queue<int> pq;
	for(int i = 1; i <= n + 1; i++)
	{
		for(int u : gr[i])
		{
			in[u]++;
		}
	}
	
	for(int i = 1; i <= n + 1; i++)
	{
		if(in[i] == 0)pq.push(-i);
	}
	
	while(!pq.empty())
	{
		int node = -pq.top();
		ans[node] = br++;
		pq.pop();
		for(int u : gr[node])
		{
			in[u]--;
			if(in[u] == 0)pq.push(-u);
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	cin >> s;
	
	n = s.size();
	for(int i = 1; i <= n; i++)
	{
		if(s[i - 1] == '<')gr[i].push_back(i + 1);
		else gr[i + 1].push_back(i);
	}
	
	topoSort();
	
	for(int i = 1; i <= n + 1; i++)cout << ans[i] << " ";
	cout << endl;
	
	return 0;
}
