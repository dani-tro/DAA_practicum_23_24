#include <iostream>
#include <stdio.h>
#include <stack>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <queue>


double m, n, a, b;
struct spice
{
	double weight, price; int idx;
	void Print()
	{
		std::cout << std::fixed << std::setprecision(3) << weight << "\n";// << price << " " << idx << "\n";
	}
};
std::vector<spice> v; 
bool cmp1(spice s1, spice s2)
{
	return s1.idx < s2.idx;
}
bool cmp2(spice s1, spice s2)
{
	return s1.price < s2.price;
}
int main()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> m;
	std::cin >> n;
	spice s;
	for (size_t i = 0; i < n; i++)
	{
		std::cin >> a >> b; s.weight = a; s.price = b; s.idx = i;
		v.push_back(s);
	}

	std::sort(v.begin(),v.end(),cmp2);
	double taken, ans = 0;

	for( int i = v.size()-1; i >= 0; i--)
	{
		if (m > 0) 
		{
			taken = fmin ( m, v[i].weight);
			m -= taken;
			v[i].weight = taken;
			ans += taken * v[i].price;
		}
		else
		{
			v[i].weight = 0;
		}
	}
	std::sort(v.begin(), v.end(), cmp1);
	
	std::cout << std::fixed << std::setprecision(2) << ans << "\n";
	for (spice s : v) s.Print();

}