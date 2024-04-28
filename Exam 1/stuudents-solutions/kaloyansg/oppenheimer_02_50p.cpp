#include <iostream>
//#include <vector>
//#include <queue>
//#include <iomanip>
//#include <math.h>
#include <algorithm>
using namespace std;

long long atoms[100005];
long long n, k;

//long long findMaxAtoms(long long left, long long right)
//{
//	if (atoms[right] - atoms[left] <= k)
//	{
//		cout << right - left + 1;
//		return;
//	}
//	else
//	{
//		mid = (left + right) / 2;
//
//	}
//}

void openhaimer()
{
	cin >> n >> k;
	for (long long i = 0; i < n; ++i)
	{
		cin >> atoms[i];
	}

	sort(atoms, atoms + n);

	long long max = 0;
	long long curr = 1;

	for (long long i = 0; i < n; ++i)
	{
		for (long long j = i+1; j < n; ++j)
		{
			if (atoms[j] - atoms[i] <= k)
			{
				curr++;
				if (curr > max)
				{
					max = curr;
				}
			}
			else
			{
				break;
			}
		}
		curr = 1;
	}

	cout << max;

	/*long long left = 0;
	long long right = n - 1;
	long long mid;*/

	/*while(right>=left)
	{
		if (atoms[right] - atoms[left] <= k)
		{
			cout << right - left + 1;
			return;
		}
		else
		{
			mid = (left + right) / 2;

			if (atoms[right] - atoms[mid] <= k)
			{

			}
		}
	}*/
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	openhaimer();
}