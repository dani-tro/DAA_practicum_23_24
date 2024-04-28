#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int n, ans = 0, mid;
long long a[100000006], k;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);

	long r, l;

	for (int i = 0; i < n; i++)
	{
		l = i;
		r = n - 1;
		while (l < r)
		{	

		    mid = (l + r) / 2;


			//cout << l << " " << r << " " << mid << endl;

			if (a[mid] - a[i] <= k)
			{
				l = mid;
				if (ans < mid - i + 1)
				{
					ans = mid - i + 1;
				}
			}
			else
			{
				r = mid;
			}

			if (l == r - 1 && a[r] - a[i] <= k)
			{
				if (ans < r - i + 1)
				{
					ans = r - i + 1;
				}
				break;
			}
			if (l == r - 1 && a[l] - a[i] <= k)
			{ 
				if (ans < l - i + 1)
				{
					ans = l - i + 1;
				}
				break;
			}
		} 
	}

	cout << ans;
	return 0;
}
