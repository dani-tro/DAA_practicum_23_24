#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
#include <iostream>    
#include <iomanip>
#include <algorithm>
#include <stack>

//std::vector<std::vector<int>> mat;
//std::vector<int> candies;

bool compareFunc(std::pair<long long, long long>& l, std::pair<long long, long long>& r)
{
	if (l.first != r.first)
	{
		return l.first < r.first;
	}
	else
	{
		return l.second < r.second;
	}
}

bool compareFunc1(std::pair<std::pair<long long, long long>, long long>& l, std::pair<std::pair<long long, long long>, long long>& r)
{
	return l.second >= r.second;
}

std::vector<std::pair<long long, long long>> intervals;
std::vector<std::pair<long long, long long>> goodIntervals;
std::vector<long long> paths;
std::vector<long long> sumOFPaths;
std::vector<std::pair<std::pair<long long, long long>, long long>> countOFIntervals;
int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::pair<long long, long long> mitko;
	long long n, m, k;
	std::cin >> n >> m >> k;
	long long elem;

	for (long long i = 0; i < n; i++)
	{
		std::cin >> elem;
		paths.push_back(elem);
	}

	int x, y;

	for (long long i = 0; i < m; i++)
	{
		std::cin >> x >> y;
		std::pair<long long, long long> x1;
		std::pair<long long, long long> y1;
		std::pair<long long, long long> both;
		both.first = x;
		both.second = y;
		x1.first = x;
		x1.second = 1;
		y1.first = y;
		y1.second = -1;
		intervals.push_back(x1);
		intervals.push_back(y1);
		goodIntervals.push_back(both);
	}
	//std::sort(intervals.begin(), intervals.end(), compareFunc);
	//std::sort(start.begin(), start.end(), compareFunc);
	//std::sort(end.begin(), end.end(), compareFunc);

	long long openIntervals = 0;

	std::sort(intervals.begin(), intervals.end(), compareFunc);

	std::stack<long long> st;

	for (long long i = 0; i < 2*m; i++)
	{
		if (intervals[i].second == 1)
		{
			openIntervals++;
			st.push(intervals[i].first);
		}
		else
		{
			long long x = st.top();
			std::pair<long long, long long> inter;
			inter.first = x;
			inter.second = intervals[i].first;
			std::pair<std::pair<long long, long long>, long long> elem;
			elem.first = inter;
			elem.second = openIntervals;
			openIntervals--;
			st.pop();
			countOFIntervals.push_back(elem);
		}
	}

	std::sort(countOFIntervals.begin(), countOFIntervals.end(), compareFunc1);

	long long counter = 0;

	for (long long j = 0; j < m; j++)
	{
		if (counter == k)
		{
			break;
		}
		int l = countOFIntervals[j].first.first - 1;
		int r = countOFIntervals[j].first.second - 1;
		for (int i = l; i <= r; i++)
		{
			while (counter < k && paths[i] > 0) {
				paths[i]--;
				counter++;
			}
			if (counter == k)
			{
				break;
			}
		}
	}

	long long sum = 0;
	sumOFPaths.push_back(sum);
	for (int i = 0; i < n; i++)
	{
		sum += paths[i];
		sumOFPaths.push_back(sum);
	}
	long long answ = 0;
	for (int i = 0; i < m; i++)
	{
		answ += sumOFPaths[goodIntervals[i].second] - sumOFPaths[goodIntervals[i].first - 1];
	}

	std::cout << answ;
	return 0;
}
