#include <bits/stdc++.h>

using namespace std;

int n, lx, rx, ly, uy, current, ans;

struct event
{
	int x, type;
	bool operator<(const event& other)
	{
		if(x != other.x)return x < other.x;
		return type > other.type;
	}
};

vector<event> x, y;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> lx >> ly >> rx >> uy;
		if(lx > rx)swap(lx, rx);
		if(ly > uy)swap(ly, uy);
		x.push_back({lx, 1});
		x.push_back({rx, -1});
		
		y.push_back({ly, 1});
		y.push_back({uy, -1});
	}
	
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	
	for(event e : x)
	{
		current += e.type;
		ans = max(ans, current);
	}
	
	for(event e : y)
	{
		current += e.type;
		ans = max(ans, current);
	}
	
	cout << ans << endl;
	return 0;
}
