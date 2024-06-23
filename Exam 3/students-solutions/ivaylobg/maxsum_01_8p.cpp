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
#include <climits>

const int MAXN = 1e5;
const int MAXK = 1e3;

int arr[MAXN];
int move[MAXN];
int n, k;
int dpR[MAXN] = { 0 };
int dpL[MAXN] = { 0 };

int solveR(int idx)
{
	
	if (idx > n) return 0;
	if (dpR[idx]) return dpR[idx];

	dpR[idx] = 0;
	for (int i = 1; i <= k; i++)
	{
		dpR[idx] = fmax(dpR[idx], solveR(idx + move[i])) ;
		//std::cout << move[i] << "  \n";
	}
	if (dpR[idx] != 0) dpR[idx] += arr[idx];
	//std::cout << "solveR " << idx << " dpR: " << dpR[idx] << " \n";
	return dpR[idx];
}

int solveL(int idx)
{
	//std::cout << "solveL " << idx << " \n";
	if (idx < 1) return 0;
	if (dpL[idx]) return dpL[idx];

	for (int i = 1; i <= k; i++)
	{
		dpL[idx] = fmax(dpL[idx], solveL(idx - move[i])) ;
		//std::cout << move[i] << "  \n";
	}
	if (dpL[idx] != 0) dpL[idx] += arr[idx];
	return dpL[idx];
}
int main()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> n >> k;
	for (size_t i = 1; i <= n; i++) std::cin >> arr[i];
	for (size_t i = 1; i <= k; i++) std::cin >> move[i];

	dpL[1] = arr[1];
	dpR[n] = arr[n];
	solveL(n);
	solveR(1);

	//for (int i = 1; i <= n; i++) std::cout << dpL[i] << " ";
	//std::cout << std::endl;
	//for (int i = 1; i <= n; i++) std::cout << dpR[i] << " ";
	//std::cout << std::endl;

	int ans = 0;
	for (int len = 1; len <= n; len++)
	{
		for (int i = 1; i <= n - len; i++)
		{
			ans = fmax(ans, dpL[i] + dpR[i + len]);
		}
	}
	std::cout << ans;





	//for (size_t i = 1; i <= n; i++) std::cout << arr[i] << " ";
	//std::cout << std::endl;
	//for (size_t i = 1; i <= k; i++) std::cout << move[i] << " ";
	//std::cout << std::endl;
	//solveR(1);
	//for (int i = 1; i <= n; i++) std::cout << dpR[i] << " ";
}