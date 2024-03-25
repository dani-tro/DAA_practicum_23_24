// O(n * log(n))

#include <bits/stdc++.h>

using namespace std;

int n, a, b, current, cnt, maxlength, bgn;

struct event
{
	int x, type;
	
	bool operator<(const event& other)
	{
		if(x != other.x)return x < other.x;
		return type > other.type;
	}
};

vector<event> v;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back({a, 1});
		v.push_back({b, -1});
	}
	
	sort(v.begin(), v.end());
	
	for(event e : v)
	{
		current += e.type;
		if(e.type == 1 && current == 1)
		{
			cnt++;
			bgn = e.x;
		}
		if(current == 0)
		{
			maxlength = max(maxlength, e.x - bgn);
		}
		
	}
	cout << cnt << " " << maxlength << endl;
	
	return 0;
}
