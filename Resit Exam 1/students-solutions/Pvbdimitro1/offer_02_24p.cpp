/*#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 10000000;

int n, k;

int arr[MAXN];

bool check(long long l, long long r)
{
	long long res = 0;

	for (int i = l; i < r; i++)
	{
		for (int j = i + 1; j <= r; j++)
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

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	long long counter = 0;

	for (int i = 0; i < n - 1; i++)
	{
		int j = i + 1;

		while(j < n)
		{
			if(check(i, j))
				++counter;

			++j;
		}
	}

	cout << counter;

	return 0;
}
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100000;

int n, k;

int arr[MAX];

long long sum(int l, int r)
{
	long long sum = 0;

	for (int i = l; i <= r; i++)
	{
		sum += arr[i];
	}

	return sum;
}

long long spared(int l, int r)
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

	long long price = 0;

	for (int i = 0; i < n; i++)
	{
		if (i + k >= n)
		{
			price += sum(i, n - 1);
			break;
		}

		int j = i + k - 1;
		long long sj1;
		long long sj2;

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