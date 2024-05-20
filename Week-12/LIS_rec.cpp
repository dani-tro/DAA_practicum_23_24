#include <bits/stdc++.h>

using namespace std;

#define MAX 10001

int n, a[MAX], d[MAX], ans;

int comp(int i)
{
	if(d[i] > 0)return d[i];
	int ans = 1;
	for(int j = i + 1; j <= n; j++)
	{
		if(a[i] < a[j])ans = max(ans, 1 + comp(j));
	}
	return d[i] = ans;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	
	int ans = 0;
	
	for(int i = 1; i <= n; i++)ans = max(ans, comp(i));
	
	cout << ans << endl;
	return 0;
}
