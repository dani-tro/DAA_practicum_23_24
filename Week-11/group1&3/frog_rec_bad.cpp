#include <bits/stdc++.h>

using namespace std;

#define MAX 101000

int n, h[MAX];

long long calc(int idx, int sum)
{
	if(idx > n)return INT_MAX;
	if(idx == n)return sum;
	
	
	return min(calc(idx + 1, sum + abs(h[idx] - h[idx + 1])), 
			calc(idx + 2, sum + abs(h[idx] - h[idx + 2])));
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> h[i];
	
	cout << calc(1, 0) << endl;
	
	return 0;
}
