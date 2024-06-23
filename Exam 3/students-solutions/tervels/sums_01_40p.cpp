#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

const int MAXN = 128;

int n, a, b, arr[MAXN];

unordered_set<int> sums;

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
			q.push(x + arr[i]);
		}
		while(!q.empty())
		{
			if (q.front() >= a && q.front() <= b)
                sums.insert(q.front());
			q.pop();
		}
        if (arr[i] >= a && arr[i] <= b)
		    sums.insert(arr[i]);
	}
	
	cout << sums.size() << endl;
	
	return 0;
}