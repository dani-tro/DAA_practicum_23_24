#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <unordered_map>
#include <iomanip>
using namespace std;

long n, k;
long long d[100006];
long long ans;
bool can_walk(long long max_dist)
{
	long long dist;
	int i = 0, j = 0;
	for (i; i < k; i++)
	{
		dist = 0;
		while (dist < max_dist)
		{
			dist += d[j];
			j++;
			if (j > n - 2)
			{
				return false;
			}
		}		
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n-1; i++)
	{
		cin >> d[i];
	}

	long long l = 0, r = 1e14;
	for (int i = 0; i < 200; i++)
	{
		long long mid = (l + r) / 2;

		// cout << l << " " << r << " " << mid << endl;
		if (can_walk(mid))
		{
			l = mid;
			ans = mid;
		}
		else
		{
			r = mid;
		}
	}

	cout << l << endl;
	
}
