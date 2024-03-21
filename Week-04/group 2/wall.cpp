#include <bits/stdc++.h>

using namespace std;

struct fragment
{
	long long height, count;
	
	bool operator<(const fragment& other)
	{
		return height > other.height;
	}
};

long long n, k, h, l, ans;

vector<fragment> v;

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> h >> l;
		v.push_back({l, h / l});
		v.push_back({h % l, 1});
	}	
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < v.size(); i++)
	{
		if(k >= v[i].count)
		{
			ans += v[i].height * v[i].count;
			k -= v[i].count;
		}
		else
		{
			ans += v[i].height * k;
			k -= k;
		}
	}
	
	cout << ans << endl;
	return 0;
}
