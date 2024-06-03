#include <bits/stdc++.h>

using namespace std;

#define MAXN 1024

#define MAXSUM 2001000

#define offset 1000100

int n, a[MAXN];

bool used[MAXSUM];

vector<int> sums;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) 
	{
		cin >> a[i];
	}
	
	for(int i = 1; i <= n; i++)
	{
		int k = sums.size();
		for(int j = 0; j < k; j++)
		{
			if(!used[sums[j] + a[i] + offset])sums.push_back(sums[j] + a[i]);
			used[sums[j] + a[i] + offset] = true;
		}
		if(!used[a[i] + offset])sums.push_back(a[i]);
		used[a[i] + offset] = true;
	}
	
	cout << sums.size() << endl;
	
	return 0;
}
