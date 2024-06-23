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

int n, p;

struct event
{
	int begin;
	int end;
	bool eventType;
	int r;

	
};

bool operator<(const event& lhs, const event& other)
{
	return lhs.end > other.end;
}

int main()
{
	cin >> n >> p;

	priority_queue<event> pq;

	int a, b;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;

		pq.push({ 0, b, 1, a });
	}

	int result = 0;
	int last = 0;

	while (p)
	{
		event temp = pq.top();
		pq.pop();

		if (temp.eventType)
		{
			pq.push({ temp.end, temp.end + temp.r, 0, temp.r });
		}
		else
		{
			pq.push({ temp.end, temp.end + temp.r, 0, temp.r });
			--p;
		}

		result += temp.end - last;
		last = temp.end;
	}

	cout << result;

	return 0;
}