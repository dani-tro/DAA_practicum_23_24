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
long long can_walk(long long max_dist)
{
	long long ans = 0;
	long long dist;
	int i = 0, j = 0;
	for (i; i < k; i++)
	{
		dist = 0;
		while (dist < max_dist)
		{
			/*
			if (j > n - 2 && dist < max_dist && i == k)
			{
				return ans;
			}
			*/
			if (j > n - 2)
			{
				return -1;
			}
			
			dist += d[j];
			j++;
			
		}
		if (i == 0)
		{
			ans = dist;
		}
		if (dist <= max_dist)
		{
			ans = max(dist, ans);
		}
		
		dist = 0;
	}
	dist = 0;
	while (j <= n - 2)
	{
		dist += d[j];
		if (dist > max_dist)
		{
			return -1;
		}
		j++;
	}
	return ans;
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

		 //cout << l << " " << r << " " << mid << endl;
		 long long can_walk_ans = can_walk(mid);
		if (can_walk_ans != -1)
		{
			//cout << " yes"<< " " << can_walk_ans << endl;
			r = mid;
			ans = can_walk_ans;
		}
		else
		{
			r = mid;
		}
	}

	cout << ans << endl;
	
}
