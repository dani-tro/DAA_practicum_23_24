#include <bits/stdc++.h>

using namespace std;

mt19937 myrand(98749835);

int n, k, x;

int pick(vector<int>& a, int k)
{
	int pivot = a[myrand() % a.size()];
	
	vector<int> smaller, equal, bigger;
	for(int x : a)
	{
		if(x < pivot)smaller.push_back(x);
		else if(x == pivot)equal.push_back(x);
		else bigger.push_back(x);
	}
	
	if(k <= smaller.size())return pick(smaller, k);
	k -= smaller.size();
	if(k <= equal.size())return pivot;
	k -= equal.size();
	return pick(bigger, k);
}

vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	
	cout << pick(v, k) << endl;
	
	return 0;
}
