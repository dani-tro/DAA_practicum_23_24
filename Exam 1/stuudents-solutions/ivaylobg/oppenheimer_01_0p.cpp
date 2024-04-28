#include <iostream>
#include <stdio.h>
#include <stack>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <queue>

int N, K;
std::vector<int> atoms; //{ 5, 9, 3, 1, 2, 7, 8, 9, 5, 8 };

bool findAtoms(int target)
{
	int i1 = 0, i2 = i1 + target - 1;

	while (i2 < atoms.size())
	{
		if ((atoms[i2] - atoms[i1]) <= K) return true;
		i1++; i2++;
	}

	return false;
}
int solve()
{
	int l = 1, r = atoms.size(), m;

	while (l < r)
	{
		m = (l + r) / 2;
		//std::cout << l << " " << m << " " << r << "\n";
		if (findAtoms(m)) l = m;
		else r = m-1;
	}

	return l;
}
int main()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> N >> K;
	int a;
	for (size_t i = 0; i < N; i++)
	{
		std::cin >> a;
		atoms.push_back(a);
	}
	std::sort(atoms.begin(),atoms.end());

	std::cout << solve();
}