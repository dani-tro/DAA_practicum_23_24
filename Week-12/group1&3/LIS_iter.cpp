#include <bits/stdc++.h>

using namespace std;

#define MAX 10001

int n, a[MAX], d[MAX], ans;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	
	for(int i = 1; i <= n; i++)d[i] = 1;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			if(a[i] < a[j])
			{
				d[j] = max(d[j], d[i] + 1);
			}
		}
		ans = max(ans, d[i]);
	}
	
	cout << ans << endl;
	return 0;
}
