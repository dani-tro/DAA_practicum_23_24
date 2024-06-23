#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
using ull =  long long;


ull leftArr[100000];
ull rightArr[100000];
ull arr[100000];
ull jumbs[1000];
ull leftMax[100000];
ull rightMax[100000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n >> k;;
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < k; i++)
	{
		cin >> jumbs[i];
	}
	
	sort(jumbs, jumbs+k);

	leftArr[0] = arr[0];
	leftMax[0] = arr[0];
	rightArr[0] = arr[n - 1];
	rightMax[0] = arr[n - 1];
	for (int i = 1; i < n; i++)
	{
		leftArr[i] = LLONG_MIN/2;
		rightArr[i] = LLONG_MIN / 2;
		for (int j = 0; j < k; j++)
		{
			int t = jumbs[j];
			if (t > i)
			{
				break;
			}
			leftArr[i] = max(leftArr[i], leftArr[i - t] + arr[i]);
			rightArr[i] = max(rightArr[i], rightArr[i - t] + arr[n-1 - i]);
		}
		leftMax[i] = max(leftArr[i], leftMax[i - 1]);
		rightMax[i] = max(rightArr[i], rightMax[i - 1]);
	}
	ull m = LLONG_MIN / 2;
	for (int i = 0; i < n-1; i++)
	{
		m = max(leftMax[i] + rightMax[n - 2 - i], m);
	}
	cout << m << endl;
}