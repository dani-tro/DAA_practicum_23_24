#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5;
long long arr[MAXN];
long long n,k;
bool eligible(long long* arr,int l,int r) {
	return arr[r] - arr[l] <= k;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> k;
	for (size_t i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	long long count = n, l = 0, r = n - 1 , maxCount = 0;
	
	while (l <= r) {
		if (!eligible(arr, l, r)) {
			l++; r--; count -= 2;
		}
		else {
			break;
		}
	}
	long long count2 = count;
	maxCount = count;
	int kl = l, kr = r;
	l--;
	while (l>=0) {
		if (eligible(arr, l, kr)) {
			count++;
			l--;

		}
		else {
			break;
		}
	}
	maxCount = max(count, maxCount);
	r++;
	while (r<n) {
		if (eligible(arr, kl, r)) {
			count2++;
			r++;

		}
		else {
			break;
		}
	}
	maxCount = max(count2, maxCount);
	cout << maxCount<<endl;
}