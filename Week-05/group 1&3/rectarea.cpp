// O(n * MAXY)

#include <bits/stdc++.h>

using namespace std;

#define MAX 21000

#define offset 10000

int n, a, b, c, d, cnt[MAX], lastx, ans;

struct event
{
	int x, l, r, type;
	bool operator<(const event& other)
	{
		return x < other.x;
	}
};

vector<event> v;

int get_cnt()
{
	int br = 0;
	for(int i = 0; i < MAX; i++)br += (cnt[i] > 0);
	return br;
}

void update(int l, int r, int type)
{
	for(int i = l; i < r; i++)cnt[i] += type;
	return;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b >> c >> d;
		a += offset;
		b += offset;
		c += offset;
		d += offset;
		if(a > c)swap(a, c);
		if(b > d)swap(b, d);
		
		v.push_back({a, b, d, 1});
		v.push_back({c, b, d, -1});
	}
	
	sort(v.begin(), v.end());
	 
	for(event e : v)
	{
		ans += (e.x - lastx) * get_cnt();
		lastx = e.x;
		update(e.l, e.r, e.type);
	}
	
	cout << ans << endl;
	return 0;
}
