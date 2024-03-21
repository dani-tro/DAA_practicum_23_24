#include <bits/stdc++.h>

using namespace std;

mt19937 myrand(98749835);

int n, x;

void quickSort(vector<int>& a)
{
	if(a.size() <= 1)return ;
	int pivot = a[myrand() % a.size()];// v[rand() % v.size()]
	
	vector<int> smaller, equal, bigger;
	
	for(int x : a)
	{
		if(x < pivot)smaller.push_back(x);
		else if(x == pivot)equal.push_back(x);
		else bigger.push_back(x);
	}
	
	quickSort(smaller);
	quickSort(bigger);
	
	a = smaller;
	for(int x : equal)a.push_back(x);
	for(int x : bigger)a.push_back(x);
	
	return;
}

vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	
	quickSort(v);
	
	for(int x : v)cout << x << " ";
	cout << endl;
	
	return 0;
}
