// O(n)

#include <bits/stdc++.h>

using namespace std;

#define MAX 10100000

#define PA pair<long long, long long>

long long n, k, f, a, b, m, p, st, ans;

deque<PA> d;

int main()
{

	cin >> n >> k;
	cin >> f >> a >> b >> m;

	d.push_back({0, 0});
	d.push_back({f, 1});
	p = f;
	for(int i = 2; i <= n; i++)
	{
		p = (p * a + b) % m;
		while(i - d.front().second > k)d.pop_front();
		st = p + d.front().first;
		while(!d.empty() && d.back().first >= st)d.pop_back();
		d.push_back({st, i});
	}
	while(n + 1 - d.front().second > k)d.pop_front();
	cout << d.front().first << endl;
	return 0;
}
