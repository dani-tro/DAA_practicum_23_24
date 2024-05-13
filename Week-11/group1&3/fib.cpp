#include <bits/stdc++.h>

using namespace std;

#define MAX 50

long long f[MAX];

long long fib(int n)
{
	if(n <= 1)return 1;
	if(f[n] != 0)return f[n];
	return f[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
	int n;
	cin >> n;
	
	cout << fib(n) << endl;
	
	return 0;
}
