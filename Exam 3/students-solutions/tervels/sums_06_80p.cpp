#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

const int MAXN = 128;

int n, a, b, arr[MAXN];

unordered_set<int> sums, potentials;

queue<int> q;

void printSet()
{
    for (int i : sums)
        cout << i << ' ';
    cout << endl;
}

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
			    q.push(tmp);
		}
        for(int x : potentials)
		{
            int tmp = x + arr[i];
            if (tmp >= a && tmp <= b)
			    q.push(tmp);
		}
		while(!q.empty())
		{
            sums.insert(q.front());
			q.pop();
		}

        if (arr[i] >= a && arr[i] <= b)
		{
            sums.insert(arr[i]);
        }
        if (arr[i] < a) potentials.insert(arr[i]);
	}
	
	cout << sums.size() << endl;
	
	return 0;
}