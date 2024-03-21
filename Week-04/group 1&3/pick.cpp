#include <bits/stdc++.h>

using namespace std;

mt19937 myrand(22122002);

int n, k, x, a;

vector<int> v;

int pick(vector<int>& v, int k)
{
	int pivot = v[myrand() % v.size()];
	vector<int> smaller, equal, bigger;
	for(int x : v)
	{
		if(x > pivot)bigger.push_back(x);
		if(x == pivot)equal.push_back(x);
		if(x < pivot)smaller.push_back(x);
	}
	if(k <= smaller.size())return pick(smaller, k);
	k -= smaller.size();
	if(k <= equal.size())return equal[0];
	k -= equal.size();
	return pick(bigger, k);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	
	cout << pick(v, n - k + 1) << endl;//selectK
	
	
	return 0;
}
