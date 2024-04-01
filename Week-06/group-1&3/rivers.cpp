//O( ~ 2^2 * 100 ^ 3)

#include <bits/stdc++.h>

using namespace std;

double L, G, w[4], s[4];

double ternary(int idx, double y)
{
	if(idx == 3)
	{
		return (L - y) / G;
	}
	double l = y, r = L, m1, m2, c1, c2;
	for(int i = 0; i < 100; i++)
	{
		m1 = l + (1.0 / 3) * (r - l);
		m2 = l + (2.0 / 3) * (r - l);
		c1 = ternary(idx + 1, m1) + sqrt((m1 - y) * (m1 - y) + w[idx] * w[idx]) / s[idx];
		c2 = ternary(idx + 1, m2) + sqrt((m2 - y) * (m2 - y) + w[idx] * w[idx]) / s[idx];
		if(c1 > c2)
		{
			l = m1;
		}
		else 
		{
			r = m2;
		}
	}
	return ternary(idx + 1, l) + sqrt((l - y) * (l - y) + w[idx] * w[idx]) / s[idx];
}

int main()
{
	cin >> L >> G;
	for(int i = 0; i < 3; i++)cin >> w[i] >> s[i];
	
	cout << setprecision(15) << ternary(0, 0) << endl;
	
	return 0;
}
