#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <unordered_map>
#include <iomanip>
using namespace std;

struct spice
{
	int id;
	double kg;
	double price;
	bool operator<(spice& other)
	{
		if (this->price == other.price) return this->kg > other.kg;
		return price > other.price;
	}
};
long mass, n;
double ans;
spice spices[105];
unordered_map<int, double> mp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> mass;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> spices[i].kg >> spices[i].price;
		spices[i].id = i;
	}

	sort(spices, spices + n);
	
	for (int i = 0; i < n; i++)
	{
		bool overflow = mass < spices[i].kg;
		if (overflow)
		{
			ans += mass * spices[i].price;
			mp[i] = mass;
			break;
		}
		else
		{
			mass -= spices[i].kg;
			ans += spices[i].kg * spices[i].price;
			mp[i] = spices[i].kg;
		}
	}

	cout << fixed << setprecision(2) << ans << endl;
	for (int i = 0; i < n; i++)
	{
		cout << fixed << setprecision(3) << mp[i] << endl;
	}


}
