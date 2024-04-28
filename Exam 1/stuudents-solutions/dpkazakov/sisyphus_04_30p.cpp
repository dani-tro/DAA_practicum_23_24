#include<iostream>
#include <iomanip>
#include <queue>
using namespace std;



const int max_size = 1000;
long int a[max_size];
pair<int, int> b[max_size];
int occ[max_size];

bool allZeroes(int length)
{
	for (int i = 0; i < length; i++)
	{
		if (a[i] != 0)
		{
			return false;
		}
	}
	return true;
}

int maxElementOcc(int length)
{
	int max = 0;
	int res = 0;
	for (int i = 0; i < length; i++)
	{
		if (occ[i] > max)
		{
			max = occ[i];
			res = i;
		}
	}
	return res;
}

int maxElementArr(int length)
{
	int max = 0;
	int res = 0;
	for (int i = 0; i < length; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			res = i;
		}
	}
	return res;
}

void updateOcc(int l, int r)
{
	for (int i = l; i < r; i++)
	{
		occ[i]++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long int n,m,k;
	int i;
	cin >> n >> m >> k;
	for ( i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < m; i++)
	{
		cin >> b[i].first;
		cin >> b[i].second;
		updateOcc(b[i].first - 1, b[i].second - 1);
	}
	
	while (k > 0 && !allZeroes(n))
	{
		int maxocc = maxElementOcc(n);
		int maxEl = maxElementArr(n);
		if (a[maxocc] < a[maxEl] && a[maxocc]!=0)
		{
			if (a[maxocc] < k)
			{
				k -= a[maxocc];
				a[maxocc] = 0;
			}
			else
			{
				a[maxocc] -= k;
				k = 0;
			}
			occ[maxocc] = 0;
		}
		else
		{
			if (a[maxEl] < k)
			{
				k -= a[maxEl];
				a[maxEl] = 0;
			}
			else
			{
				a[maxEl] -= k;
				k = 0;
			}
			occ[maxEl] = 0;
		}
	}

	long int result = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = b[i].first-1; j < b[i].second; j++)
		{
			result += a[j];
		}
	}
	cout << result;
}