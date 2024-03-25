// O(n * log(n))

#include <bits/stdc++.h>

using namespace std;

#define MAX 110000

int n, m, a, b, current, ans[MAX];

struct event
{
	int x, type, idx;
	
	bool operator<(const event& other)
	{
		if(x != other.x)return x < other.x;
		return type > other.type;
	}
};

vector<event> v;

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if(a > b)swap(a, b);
		v.push_back({a, 1, 0});
		v.push_back({b, -1, 0});
	}
	
	for(int i = 0; i < m; i++)
	{
		cin >> a;
		v.push_back({a, 0, i});
	}

	sort(v.begin(), v.end());
	
	for(event e : v)
	{
		current += e.type;
		if(e.type == 0)ans[e.idx] = current;
	}
	
	for(int i = 0; i < m; i++)cout << ans[i] << " ";
	cout << endl;
	
	return 0;
}
