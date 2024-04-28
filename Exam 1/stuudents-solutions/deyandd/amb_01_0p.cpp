#include <iostream>
#include<algorithm>
using namespace std;

long arr[100000];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	long n, k; cin >> n >> k;
	for (long i = 0; i < n - 1; i++)
	{
		cin >> arr[i];
	}
	long long low = 0, high = 1 << 5+1;
	while (high - low  >1 ) {
		long dist = (high + low) / 2;
		long l = 0; long h = 1;
		long sum = arr[0], conut = k;
		bool falg = false;
		while (h < n)
		{
			sum += arr[h];
			while (sum > dist)
			{
				conut--;
				sum -= arr[l];
				l++;
				if (conut < 0) {
					falg = true;
					break;
				}
			}
			if (falg) {
				break;
			};
			h++;
		}
		
		if (falg) {
			cout << low << " "  << high<< endl;
			low = dist;
		}
		else {
			high = dist;
		}

	}
	long res = 1 << 30;
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i]> high && arr[i] - high < res) {
			res = arr[i];
		}
	}
	cout << res << endl;
}

