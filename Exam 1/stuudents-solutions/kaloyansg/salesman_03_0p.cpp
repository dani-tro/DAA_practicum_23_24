#include <iostream>
//#include <vector>
#include <queue>
#include <iomanip>
//#include <math.h>
#include <algorithm>
using namespace std;

//long long atoms[100005];
//long long n, k, m;
//
////long long findMaxAtoms(long long left, long long right)
////{
////	if (atoms[right] - atoms[left] <= k)
////	{
////		cout << right - left + 1;
////		return;
////	}
////	else
////	{
////		mid = (left + right) / 2;
////
////	}
////}
//
//void openhaimer()
//{
//	cin >> n >> k;
//	for (long long i = 0; i < n; ++i)
//	{
//		cin >> atoms[i];
//	}
//
//	sort(atoms, atoms + n);
//
//	long long max = 0;
//	long long curr = 1;
//
//	for (long long i = 0; i < n; ++i)
//	{
//		for (long long j = i+1; j < n; ++j)
//		{
//			if (atoms[j] - atoms[i] <= k)
//			{
//				curr++;
//				if (curr > max)
//				{
//					max = curr;
//				}
//			}
//			else
//			{
//				break;
//			}
//		}
//		curr = 1;
//	}
//
//	cout << max;
//
//	/*long long left = 0;
//	long long right = n - 1;
//	long long mid;*/
//
//	/*while(right>=left)
//	{
//		if (atoms[right] - atoms[left] <= k)
//		{
//			cout << right - left + 1;
//			return;
//		}
//		else
//		{
//			mid = (left + right) / 2;
//
//			if (atoms[right] - atoms[mid] <= k)
//			{
//
//			}
//		}
//	}*/
//}
//

struct item
{
	int index;
	double quantity, price;
};
bool operator<(const item& a, const item& b)
{
	return a.price <= b.price;
}
priority_queue<item> items;

struct pack
{
	int index;
	double quntity;
};
bool operator<(const pack& a, const pack& b)
{
	return a.index >= b.index;
}
priority_queue<pack> packs;


void salesman()
{
	int M, n;
	cin >> M >> n;
	double m = M;
	item currItem;
	for (int i = 0; i < n; ++i)
	{
		currItem.index = i + 1;
		cin >> currItem.quantity >> currItem.price;
		items.push(currItem);
	}

	double s = 0;

	while (!items.empty() && m >= 0)
	{
		currItem = items.top();
		items.pop();

		if (currItem.quantity <= m)
		{
			s += currItem.quantity * currItem.price;
			m -= currItem.quantity;
			packs.push({ currItem.index, currItem.quantity });
		}
		else
		{
			s += m * currItem.price;
			packs.push({ currItem.index, (double)m });
			break;
		}
	}

	cout << fixed << setprecision(2) << s << endl;
	pack currPack;
	while (!packs.empty())
	{
		currPack = packs.top();
		packs.pop();
		cout << fixed << setprecision(3) << currPack.quntity << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//openhaimer();
	salesman();
}