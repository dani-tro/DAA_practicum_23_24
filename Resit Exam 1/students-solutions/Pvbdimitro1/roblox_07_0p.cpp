#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 10000000;

unsigned long long n, k;

int arr[MAXN];

bool check(long long l, long long r)
{
	unsigned long long res = 0;

	for (long long i = l; i < r; i++)
	{
		for (long long j = i + 1; j <= r; j++)
		{
			res += arr[i] * arr[j];

			if (res >= k)
				return true;
		}
	}

	return false;
}

int main()
{
	cin >> n >> k;

	for (long long i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	long long counter = 0;

	for (long long i = 0; i < n - 1; i++)
	{
		long long l = i + 1;
		long long r = n - 1;
		long long mid;

		while (l < r)
		{
			mid = l + (r - l) / 2;

			if (check(i, mid))
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}

		counter += n - l;
	}

	cout << counter;

	return 0;
}
/*
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>


const int MAX = 100006;

int n, k;

int arr[MAX];

unsigned long long sum(int l, int r)
{
	unsigned long long sum = 0;

	for (int i = l; i <= r; i++)
	{
		sum += arr[i];
	}

	return sum;
}

unsigned long long spared(int l, int r)
{
	int s = (r - l + 1) / k;

	return sum(r - s + 1, r);
}

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n, greater<int>());

	unsigned long long price = 0;

	for (int i = 0; i < n; i++)
	{
		if (i + k - 1 >= n)
		{
			price += sum(i, n - 1);
			break;
		}

		int j = i + k - 1;
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
*/