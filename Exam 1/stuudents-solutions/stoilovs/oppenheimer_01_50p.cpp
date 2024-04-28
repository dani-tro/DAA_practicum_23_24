#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
#include <iostream>    
#include <iomanip>
#include <algorithm>

//std::vector<std::vector<int>> mat;
//std::vector<int> candies;

std::vector<int> atoms;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	long long K;
	long long N;
	std::cin >> N >> K;
	int atom;
	for (int i = 0; i < N; i++)
	{
		std::cin >> atom;
		atoms.push_back(atom);
	}


	std::sort(atoms.begin(), atoms.end());
	int size = atoms.size();
	long long maxCounter = 1;
	for (int i = 0; i < size - 1; i++)
	{
		long long counter = 1;
		for (int j = i+1; j < size; j++)
		{
			if (atoms[j] - atoms[i] > K)
			{
				break;
			}
			counter++;
		}
		maxCounter = std::max(counter, maxCounter);
	}
	std::cout << maxCounter;
	return 0;
}
