#include<iostream>
#include<vector>
#include<algorithm>


//input: 
// 4 2
// 3 5 2
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

	std::pair<int, int> limitNumber;
	int curRes1=0, curRes2 = 0;
	limitNumber = newNumbers[newNumbers.size() - 1];
	for (int i = 0; i < newNumbers.size()-1; i++) {
		if (limitNumber.second - newNumbers[i].second <= limit) {
			curRes1 = limitNumber.first - newNumbers[i].first;
			break;
		}
	}

	limitNumber = newNumbers[0];
	for (int i = newNumbers.size() - 1; i>0; i--) {
		if (newNumbers[i].second - limitNumber.second <= limit) {
			curRes2 = newNumbers[i].first - limitNumber.first;
			break;
		}
	}

	//std::cout << curRes1 << curRes2;
	if (curRes1 >= curRes2) return curRes1;
	else return curRes2;
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