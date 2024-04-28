#include <iostream>
#include <iomanip>
#include<algorithm>
using namespace std;

struct Element
{
	double kg;
	double lv;
	long ind;
	bool operator <(Element& other) {
		return this->lv > other.lv;
	}
};
struct Result
{
	double kg;
	long ind;
	bool operator <(Result& other) {
		return this->ind < other.ind;
	}
};
Element arr[100000];
Result res[100000];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	long n; double m; cin >> m >> n;
	double sum = 0;
	for (long i = 0; i < n; i++)
	{
		double kg, lv; cin >> kg >> lv;
		arr[i] = Element{kg, lv,i};
	}
	sort(arr, arr +n);
	long ind = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (m > arr[i].kg) {
			sum += arr[i].kg * arr[i].lv;
			m -= arr[i].kg;
			res[ind] = Result{ arr[i].kg, arr[i].ind};
			ind++;
		}
		else {
			sum += m * arr[i].lv;
			res[ind] = Result{ m, arr[i].ind };
			ind++;
			break;
		}
	}
	sort(res, res + ind);
	cout << fixed << setprecision(2) << sum <<" ";
	for (size_t i = 0; i < ind; i++)
	{
		cout << fixed << setprecision(3) << res[i].kg  << " ";
	}
}

