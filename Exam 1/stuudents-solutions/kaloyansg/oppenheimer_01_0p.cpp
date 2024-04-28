#include <iostream>
//#include <vector>
//#include <queue>
//#include <iomanip>
//#include <math.h>
#include <algorithm>
using namespace std;


long long atoms[100005];
long long n, k;
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
	long long currMin = 0;

	//currMin = atoms[0];
	long long j = n - 1;
	long long i = 0;
	//for (i = 0; i < n; ++i)
	while(j>=i)
	{
		if (atoms[j] - atoms[i] <= k)
		{
			cout << j-i + 1;
			return;
		}
		else
		{
			if (atoms[i + 1] - atoms[i] >= atoms[j] - atoms[j - 1])
				++i;
			else
				--j;
		}

		/*if (atoms[i] <= currMin + k)
		{
			++curr;
		}
		else
		{
			currMin = atoms[i];
			curr = 1;
		}

		if (max < curr)
			max = curr;*/
	}

	//cout << max;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	openhaimer();
}