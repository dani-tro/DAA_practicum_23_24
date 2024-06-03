#include <bits/stdc++.h>

using namespace std;

#define MAXN 1024

int n, a[MAXN];

unordered_set<int> sums;

queue<int> q;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) 
	{
		cin >> a[i];
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int x : sums)
		{
			q.push(x + a[i]);
		}
		while(!q.empty())
		{
			sums.insert(q.front());
			q.pop();
		}
		sums.insert(a[i]);
	}
	
	cout << sums.size() << endl;
	
	return 0;
}
