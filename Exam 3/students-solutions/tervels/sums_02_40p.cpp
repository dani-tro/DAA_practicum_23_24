#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

const int MAXN = 128;

int n, a, b, arr[MAXN];

unordered_set<long long> sums;

queue<long long> q;

int main()
{
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++) 
	{
		cin >> arr[i];
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(long long x : sums)
		{
			q.push(x + arr[i]);
		}
		while(!q.empty())
		{
            long long curr = q.front();
			if (curr >= a && curr <= b)
                sums.insert(curr);
			q.pop();
		}
        if (arr[i] >= a && arr[i] <= b)
		    sums.insert(arr[i]);
	}
	
	cout << sums.size() << endl;
	
	return 0;
}