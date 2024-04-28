#include<iostream>
#include<vector>
#include<algorithm>


int findMaximumElements(std::vector<int> numbers, int limit){
	std::vector<std::pair<int, int>> newNumbers;
	std::pair<int, int> element;
	for (int i = 0; i < numbers.size(); i++) {
		element.first = i;
		element.second = numbers[i];
		newNumbers.push_back(element);
	}
	//sort by second element
	struct {
		bool operator()(const std::pair<int,int>& lh, const std::pair<int, int>& rh) const
		{
			return lh.second < rh.second;
		}
	} customLess;
	std::sort(newNumbers.begin(), newNumbers.end(), customLess);

	int length = newNumbers.size();
	int optimum = INT_MIN;
	for (int i = 0; i < length; i++) {
		for (int j = length-1; j > i; j--) {
			if (newNumbers[j].second - newNumbers[i].second <= limit) {
				optimum = (j - i+1 > optimum) ? (j - i+1) : optimum;
				break;
			}
		}
	}
	return optimum;
}

int main() {
	int numbersN, limit,element;
	std::cin >> numbersN >> limit;
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::vector<int> crises;
	while (numbersN !=0 ) {
		std::cin >> element;
		crises.push_back(element);
		numbersN--;
	}
	int result = findMaximumElements(crises, limit);
	std::cout << result;
}