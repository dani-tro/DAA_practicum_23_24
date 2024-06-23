#include <iostream>
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