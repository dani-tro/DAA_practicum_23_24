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

//struct item
//{
//	int index;
//	double quantity, price;
//};
//bool operator<(const item& a, const item& b)
//{
//	return a.price <= b.price;
//}
//priority_queue<item> items;
//struct pack
//{
//	int index;
//	double quntity;
//};
//bool operator<(const pack& a, const pack& b)
//{
//	return a.index >= b.index;
//}
//priority_queue<pack> packs;
//void salesman()
//{
//	int M, n;
//	cin >> M >> n;
//	double m = M;
//	item currItem;
//	for (int i = 0; i < n; ++i)
//	{
//		currItem.index = i + 1;
//		cin >> currItem.quantity >> currItem.price;
//		items.push(currItem);
//	}
//
//	double s = 0;
//
//	while (!items.empty())
//	{
//		if (m < 0.001)
//			break;
//
//		currItem = items.top();
//		items.pop();
//
//		if (currItem.quantity <= m)
//		{
//			s += currItem.quantity * currItem.price;
//			m -= currItem.quantity;
//			packs.push({ currItem.index, currItem.quantity });
//		}
//		else
//		{
//			s += m * currItem.price;
//			packs.push({ currItem.index, (double)m });
//			break;
//		}
//	}
//
//	while (!items.empty())
//	{
//		currItem = items.top();
//		items.pop();
//		packs.push({ currItem.index, 0 });
//	}
//
//	cout << fixed << setprecision(2) << s << endl;
//	pack currPack;
//	while (!packs.empty())
//	{
//		currPack = packs.top();
//		packs.pop();
//		cout << fixed << setprecision(3) << currPack.quntity << endl;
//	}
//}
//

long long n, m, k;

struct point { long long index; long long type; };

point points[2000006];

bool cmpPoints(const point& a, const point& b)
{
	if (a.index == b.index) return a.type > b.type;
	return a.index < b.index;
}

bool operator<(const point& a, const point& b)
{
	if (a.type == b.type) return a.index < b.index;
	if (a.type > b.type) return true;
	return false;
}

long long planina[100005];

point obshtaTejest[100005];

void sezif()
{
	cin >> n >> m >> k;

	for (size_t i = 0; i < n; ++i)
		cin >> planina[i];

	long long a;
	long long index = 0;
	for (size_t i = 0; i < m; ++i)
	{
		cin >> a;
		points[index] = { a-1,1 };
		++index;
		cin >> a;
		points[index] = { a-1,-1 };
		++index;
	}

	m = m * 2;
	sort(points, points + m, cmpPoints);
	long long tejest = 0;
	long long j = 0;

	for (long long i = 0; i < n; ++i)
	{
		if (i == points[j].index && points[j].type > 0)
		{
			tejest += points[j].type;
			++j;
		}
		else if (i == points[j].index)
		{
			obshtaTejest[i] = { i,tejest };
			tejest += points[j].type;
			++j;
			continue;
		}
		obshtaTejest[i] = { i,tejest };
	}


	sort(obshtaTejest, obshtaTejest + n);

	j = 0;
	for (size_t i = 0; i < k; i++)
	{
		while(planina[obshtaTejest[j].index] == 0 && j < n)
			++j;
		if (j >= n)
			break;
		planina[obshtaTejest[j].index]--;
	}

	long long sum = 0;
	for (size_t i = 0; i < n; ++i)
	{
		sum += obshtaTejest[i].type * planina[obshtaTejest[i].index];
	}

	cout << sum;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//openhaimer();
	//salesman();
	sezif();
}