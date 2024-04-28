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
std::vector<int> pos;

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
	int val = atoms[0];
	int position = 0;
	for (int i = 1; i < N; i++)
	{
		if (val != atoms[i])
		{
			pos.push_back(position);
			val = atoms[i];
			position = i;
		}
	}
	pos.push_back(position);
	int size1 = pos.size();
	for (int i = 0; i < size1 - 1; i++)
	{
		long long counter = 0;
		for (int j = i + 1; j < size1; j++)
		{
			if (atoms[pos[j]] - atoms[pos[i]] > K)
			{
				std::cout << "pos[i]: " << pos[i]<<std::endl;
				std::cout << "pos[j]: " << pos[j] << std::endl;
				counter = pos[j] - pos[i];
				break;
			}
			else if (j == size1 - 1)
			{
				counter = size - pos[i];
			}
		}
		maxCounter = std::max(counter, maxCounter);
	}
	/*for (int i = 0; i < size - 1; i++)
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
	}*/
	std::cout << maxCounter;
	return 0;
}
