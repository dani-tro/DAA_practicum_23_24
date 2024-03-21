// O(n * log(n)) - average

#include <bits/stdc++.h>

using namespace std;

mt19937 myrand(22122002);

int n, a;

vector<int> v;

void quickSort(vector<int>& v)
{
	if(v.size() <= 1)return ;
	int pivot = v[myrand() % v.size()];
	
	vector<int> smaller, equal, bigger;
	
	for(int x : v)
	{
		if(x < pivot)smaller.push_back(x);
		else if(x == pivot)equal.push_back(x);
		else bigger.push_back(x);
	}
	
	quickSort(smaller);
	quickSort(bigger);
	
	v = smaller;
	for(int x : equal)v.push_back(x);
	for(int x : bigger)v.push_back(x);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	
	quickSort(v);
	
	for(int x : v)cout << x << " ";
	cout << endl;
	return 0;
}
