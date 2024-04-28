#include <iostream>
#include<algorithm>
using namespace std;

long arr[100000];
bool check[100000];
pair<long, long> intervals[100000];
struct Event
{
	long value;
	int type;
	bool operator <(Event& other) {
		if (this->value != other.value) {
			return this->value < other.value;
		}
		return this->type < other.type;
	}
};
Event events[100000];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	long n, m, k; cin >> n >> m >> k;
	long sum = 0;
	for (long i = 1; i <= n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	for (size_t i = 0; i < m; i++)
	{
		long l, r;
		cin >> l >> r;
		events[2 * i] = Event{ l, 1 };
		events[2 * i + 1] = Event{ r, -1 };
		intervals[i] = pair<long, long>(l, r);
	}
	sort(events, events + 2 * m);
	while (0 < k)
	{
		long currCount = 0;
		long maxCount = 0;
		long el = 0;
		Event* curr = events;
		Event* end = curr + 2 * m;
		for (size_t i = 1; curr != end && i <= n; i++)
		{
			if (check[i]) continue;
			while (curr != end && curr->value <= i)
			{
				if (curr->type == 1) {
					currCount++;
				}
				else {
					currCount--;
				}
				curr++;
			}
			if (currCount > maxCount) {
				maxCount = currCount;
				el = i;
			}

		}
		if (k > arr[el]) {
			sum -= arr[el];
			k -= arr[el];
			arr[el] = 0;
			check[el] = true;
		}
		else {
			sum -= k;
			arr[el] -= k;
			k = 0;
			break;
		}
		if (sum <= 0) {
			sum = 0;
			break;
		}
	}
	long res = 0;
	for (size_t i = 0; i < m; i++)
	{
		auto curr = intervals[i];
		for (size_t j = curr.first; j <= curr.second; j++) {
			res += arr[j];
		}
	}
	cout << res;
}

