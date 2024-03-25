// O(log(2e9))

#include <bits/stdc++.h>

using namespace std;

long long n, f, l = 1, r, mid, ans;

long long sum(long long m)
{
	return f * (m - 1) + (m - 2) * (m - 1) / 2;
}

int main()
{
	cin >> n >> f;
	r = 2e9;
	
	while(l < r)
	{
		mid = (l + r) / 2; // l + (r - l) / 2
		if(sum(mid) < n)
		{
			l = mid + 1;
		}
		else
		{
			ans = mid;
			r = mid;
		}
	}
	
	cout << l - 1 << endl;
	
	return 0;
}
