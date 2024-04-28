#include <iostream>>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

const long MAX_SIZE = 10000000;

long apartments[MAX_SIZE];


int main()
{	
	long n, k;
	cin >> n >> k;
	for (long i = 0; i < n; i ++) 
	{
		cin >> apartments[i];
	}

	long max = 0;
	long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += apartments[i];
	}
	double average = sum / (k * 2);
	long currSum = 0;
	for (int i = 0; i < n; i++) {
		currSum += apartments[i];
		if (currSum >= average) {
			if (max < currSum) {
				max = currSum;
			}
			currSum = 0;
		}
	}

	cout << max;
	

}