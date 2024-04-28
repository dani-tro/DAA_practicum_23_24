#include<iostream>
#include <iomanip>
#include <queue>
using namespace std;


struct triplet
{
	long double first;
	long double second;
	long int ogpos;
	
	friend bool operator<(triplet left,triplet right)
	{
		return left.first < right.first;
	}

};

const int MAX_SIZE = 1000;
triplet a[MAX_SIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    long m, n,i;
	cin >> m;
	cin >> n;
	long double x, y,result = 0;
	for ( i = 0; i < n; i++)
	{
		cin >> y>>x;
		a[i].first = x;
		a[i].second = y;
		a[i].ogpos = i;
	}
	priority_queue < triplet, vector<triplet>> pq;
	for ( i = 0; i < n; i++)
	{
		pq.push(a[i]);
	}
	for (i = 0; i < n; i++)
	{
		auto curr = pq.top();
		pq.pop();
		if (m >= curr.second)
		{
			result += curr.second * curr.first;
			m -= curr.second;
			a[curr.ogpos].second = curr.second;
		}
		else if (m < curr.second && m>0)
		{
			result += m * curr.first;
			a[curr.ogpos].second = m;
			m = 0;
		}
		

	}
	cout<< fixed << setprecision(2) << result << "\n";
	for ( i = 0; i < n; i++)
	{
		cout << fixed << setprecision(3) << a[i].second <<"\n";
	}
	return 0;

}