#include <bits/stdc++.h>

using namespace std;

#define MAXDAYS 366

#define MAXN 21

#define MAXK 4000

int n, k = 1;

double dp1[MAXDAYS][MAXK], dp2[MAXDAYS][MAXK][MAXN];

double prob2(int days, int rem, int x)
{
	
	if(rem == 0)return x == 0;
	if(x < 0)return 0;
	
	if(dp2[days][rem][x] != -1)return dp2[days][rem][x];
	
	//cout << days << " " << rem << " " << x << endl;
	double ans = prob2(days, rem - 1, x - 1) * (1.0 / days) +
				 prob2(days, rem - 1, x) * (1.0 - (1.0 / days));
		
	return dp2[days][rem][x] = ans;
}

double prob1(int days, int k)
{
	if(days == 0 || k < n)return 1.0;
	
	if(dp1[days][k] != -1)return dp1[days][k];
	//cout << days << " " << k << endl;
	double ans = 0.0;
	for(int i = 0; i < n; i++) ans += prob1(days - 1, k - i) * prob2(days, k, i);
	
	return dp1[days][k] = ans;
}

int main()
{
	cin >> n;
	
	for(int i = 0; i < MAXDAYS; i++)
	{
		for(int j = 0; j < MAXK; j++)
		{
			dp1[i][j] = -1;
			for(int t = 0; t < MAXN; t++)dp2[i][j][t] = -1;
		}
	}
	
	while(prob1(365, k) >= 0.5)k++;
	
	
	cout << k << endl;
	
	return 0;
}
