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

bool compareFunc(std::pair<int, int>& l, std::pair<int, int>& r)
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

bool compareFunc1(std::pair<std::pair<int, int>, int>& l, std::pair<std::pair<int, int>, int>& r)
{
	return l.second >= r.second;
}

std::vector<std::pair<int, int>> intervals;
std::vector<std::pair<int, int>> goodIntervals;
std::vector<int> paths;
std::vector<int> sumOFPaths;
std::vector<std::pair<std::pair<int, int>, int>> countOFIntervals;
int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::pair<int, int> mitko;
	int n, m, k;
	std::cin >> n >> m >> k;
	int elem;

	for (int i = 0; i < n; i++)
	{
		std::cin >> elem;
		paths.push_back(elem);
	}

	int x, y;

	for (int i = 0; i < m; i++)
	{
		std::cin >> x >> y;
		std::pair<int, int> x1;
		std::pair<int, int> y1;
		std::pair<int, int> both;
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

	int openIntervals = 0;

	std::sort(intervals.begin(), intervals.end(), compareFunc);

	std::stack<int> st;

	for (int i = 0; i < 2*m; i++)
	{
		if (intervals[i].second == 1)
		{
			openIntervals++;
			st.push(intervals[i].first);
		}
		else
		{
			int x = st.top();
			std::pair<int, int> inter;
			inter.first = x;
			inter.second = intervals[i].first;
			std::pair<std::pair<int, int>, int> elem;
			elem.first = inter;
			elem.second = openIntervals;
			openIntervals--;
			st.pop();
			countOFIntervals.push_back(elem);
		}
	}

	std::sort(countOFIntervals.begin(), countOFIntervals.end(), compareFunc1);

	int counter = 0;

	for (int j = 0; j < m; j++)
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

	int sum = 0;
	sumOFPaths.push_back(sum);
	for (int i = 0; i < n; i++)
	{
		sum += paths[i];
		sumOFPaths.push_back(sum);
	}
	int answ = 0;
	for (int i = 0; i < m; i++)
	{
		answ += sumOFPaths[goodIntervals[i].second] - sumOFPaths[goodIntervals[i].first - 1];
	}

	std::cout << answ;
	return 0;
}
