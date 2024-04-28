#include <iostream>
#include<queue>
using namespace std;

long arr[10001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	long n, k; cin >> n >> k;
	for (long i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	long low = 0, high = 0;
	long count = 0;
	while (high < n)
	{
		if (arr[high] - arr[low] > k) {
			count = max(count, high - low);
			while (arr[high] - arr[low] > k)
			{
				low++;
			}
		}
		high++;
	}
	count = max(count, high - low);
	cout << count << endl;
}