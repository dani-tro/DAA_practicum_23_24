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
	cin >> n >> k;
	for (size_t i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	long long count = 1,l = n-2,r = n-1,maxCount=0;
	
	while (r>0 ) {
		if (eligible(arr, l, r)) {
			count++;
			l--;
		}
		else {
			break;
		}
	}
	maxCount = count; 
	count = 1;
	l = 0; r = 1;
	while (l < n - 1) {
		if (eligible(arr, l, r)) {
			r++;
		}
		else {
			break;
		}
	}
	maxCount = max(count, maxCount);
	cout << maxCount;
}