#include <iostream>
#include<algorithm>
using namespace std;

long arr[100000];
long dist[100000];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	long n, k; cin >> n >> k;
	for (long i = 1; i < n; i++)
	{
		cin >> arr[i];
		dist[i] = arr[i];
	}
	sort(dist, dist + n);
	long low = 1, high = n;
	while (high - low > 1)
	{
		long mid = (high + low) / 2;
		long sum = 0, tv = k;
		long right = 1;
		while (right < n)
		{
			sum += arr[right];
			if (sum > dist[mid]) {
				sum = 0;
				tv--;
			}
			right++;
		}
		tv--;
		if (tv < 0){
			low = mid;
		}
		else {
			high = mid;
		}
		cout << low << " " << high << endl;
	}
	cout << dist[high];
}

