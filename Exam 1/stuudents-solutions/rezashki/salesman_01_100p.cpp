#include <iostream>
#include <algorithm>
#include<iomanip>
#include<queue>
using namespace std;
double capacity, goods;
int getMax(double* arr) {
	double max1 = 0,max2=0;
	for (size_t i = 0; i < goods; i++)
	{
		if (max1 < arr[i])
		{
			max2 = i;
			max1 = arr[i];
		}
	}
	return max2;
}
int main()
{
	double a[100]{0}, b[100], c[100]{ 0 };
	//double a, b;
    cin >> capacity >> goods;
	for (size_t i = 0; i < goods; i++)
	{
		cin >> a[i] >> b[i];
		c[i] =a[i];
	}
	
	double ans = 0;
	while (capacity > 0) {
		int maxI = getMax(b);
		if (a[maxI] < capacity) {
			capacity -= a[maxI];
			ans += a[maxI] * b[maxI];
			//cout << a[maxI] <<" " << b[maxI] << endl;
			b[maxI] = 0;
			a[maxI] = 0;
		}
		else {
			a[maxI] -= capacity;
			ans += capacity * b[maxI];
			capacity = 0;
		}
			
	}
	cout << fixed << setprecision(2) << ans << endl;;
	for (size_t i = 0; i < goods; i++)
	{
		cout << fixed << setprecision(3) << c[i] - a[i]<< endl;;
	}
}