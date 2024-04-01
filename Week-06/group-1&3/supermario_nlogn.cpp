// O (n * log(n))

#include <bits/stdc++.h>

using namespace std;

#define MAX 10100000

#define PA pair<long long, long long>

long long n, k, f, a, b, m, p[MAX], dp[MAX];

priority_queue<PA, vector<PA>, greater<PA> > pq;

int main()
{
	
	cin >> n >> k;
	cin >> f >> a >> b >> m;
	
	p[1] = f;
	for(int i = 2; i <= n; i++)p[i] = (p[i - 1] * a + b) % m;
	
	for(int i = n; i > n - k; i--)
	{
		dp[i] = 0;
		pq.push({p[i] + dp[i], i});
	}
	
	for(int i = n - k; i >= 0; i--)
	{
		while(!pq.empty() && pq.top().second - i > k)pq.pop();
		dp[i] = pq.top().first;
		pq.push({p[i] + dp[i], i});
	}
	cout << dp[0] << endl;
	
	return 0;
}
