#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100006;

long long n, k;

long long arr[MAX];

unsigned long long sum(long long l, long long r)
{
	unsigned long long sum = 0;

	for (long long i = l; i <= r; i++)
	{
		sum += arr[i];
	}

	return sum;
}

unsigned long long spared(int l, int r)
{
	long long s = (r - l + 1) / k;

	return sum(r - s + 1, r);
}

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n, greater<int>());

	unsigned long long price = 0;

	for (long long i = 0; i < n; i++)
	{
		long long j = i + k - 1;

		if (j >= n)
		{
			price += sum(i, n - 1);
			break;
		}

		unsigned long long sj1;
		unsigned long long sj2;

		while (j < n)
		{
			sj1 = spared(i, j);
			sj2 = spared(i, j + 1);

			if (sj1 <= sj2)
			{
				++j;
			}
			else
			{
				price += sum(i, j) - sj1;
				i = j;

				break;
			}
		}
		
		if (j == n)
		{
			price += sum(i, j - 1) - sj1;
			break;
		}
		
	}

	cout << price;

	return 0;
}