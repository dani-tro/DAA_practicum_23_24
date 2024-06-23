#include <iostream>
#include <set>
#include <queue>

using namespace std;

const int MAXN = 128;

int n, a, b, arr[MAXN];

set<int> sums;

queue<int> q;

int main()
{
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++) 
	{
		cin >> arr[i];
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int x : sums)
		{
            int tmp = x + arr[i];
            if (tmp >= a && tmp <= b)
			    q.push(x + arr[i]);
		}
		while(!q.empty())
		{
            sums.insert(q.front());
			q.pop();
		}

        if (arr[i] >= a && arr[i] <= b)
		    sums.insert(arr[i]);
	}
	
	cout << sums.size() << endl;
	
	return 0;
}