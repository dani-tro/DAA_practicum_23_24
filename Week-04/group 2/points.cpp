#include <bits/stdc++.h>

using namespace std;

struct event
{
	int x, type, idx;
	bool operator<(const event& other)
	{
		if(x != other.x)return x < other.x;
		return type > other.type;
	}
};

vector<event> xs;
int ans[100000];

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		int x1, x2;
		cin >> x1 >> x2;
		if(x1 > x2) swap(x1, x2);
		xs.push_back({x1, 1});
		xs.push_back({x2, -1});
	}
	for(int i = 0; i < m; i++) {
		int x;
		cin >> x;
		xs.push_back({x, 0, i});
	}
	
	sort(xs.begin(), xs.end());
	
	int c = 0;
	for(event& e : xs) {
		if(!e.type) {
			ans[e.idx] = c;
		}
		c += e.type;
	}
	
	for(int i = 0; i < m; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}
