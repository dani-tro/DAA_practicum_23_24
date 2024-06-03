#include <bits/stdc++.h>

using namespace std;

#define MAX 1024

#define MAXSUM 2001000

int n, a[MAX], sums[MAXSUM], v[MAXSUM], tmp[MAXSUM], s1, s2, s3;

void merge()
{
	int l = 0, r = 0;
	s3 = 0;
	
	while(l < s1 && r < s2)
	{
		if(sums[l] <= v[r])
		{
			if(s3 == 0 || tmp[s3 - 1] != sums[l])
			{
				tmp[s3++] = sums[l];
			}
			l++;
		}
		else
		{
			if(s3 == 0 || tmp[s3 - 1] != v[r])
			{
				tmp[s3++] = v[r];
			}
			r++;
		}
	}
	
	while(l < s1)
	{
		if(s3 == 0 || tmp[s3 - 1] != sums[l])
		{
			tmp[s3++] = sums[l];
		}
		l++;
	}
	
	while(r < s2)
	{
		if(s3 == 0 || tmp[s3 - 1] != v[r])
		{
			tmp[s3++] = v[r];
		}
		r++;
	}
	
	for(int i = 0; i < s3; i++)sums[i] = tmp[i];
	s1 = s3;
	
	return ;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) 
	{
		cin >> a[i];
	}
	
	for(int i = 1; i <= n; i++)
	{
		s2 = 0;
		for(int j = 0; j < s1; j++)
		{
			v[s2++] = sums[j] + a[i];
		}
		
		merge();
		s2 = 1;
		v[0] = a[i];
		merge();
	}
	cout << s1 << endl;
	
	return 0;
}
