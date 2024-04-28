#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int n, ans = 0;
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

	int r = n-1, l = 0;

	for (int i = 0; i < n; i++)
	{
		l = i;
		int mid = (l + r) / 2;
		if (a[mid] - a[i] <= k)
		{
			l = mid;
			ans = max(ans, mid);
		}
		else
		{
			r = mid;
		}

	}

	cout << ans;
	return 0;
}
