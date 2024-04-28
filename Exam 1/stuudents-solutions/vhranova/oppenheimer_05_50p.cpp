#include<iostream>
#include<vector>
#include<algorithm>


long long findMaximumElements(std::vector<int> numbers, long long limit){
	std::vector<std::pair<int, int>> newNumbers;
	std::pair<int, int> element;
	for (long long i = 0; i < numbers.size(); i++) {
		element.first = i;
		element.second = numbers[i];
		newNumbers.push_back(element);
	}

	//sort by second element
	struct {
		bool operator()(const std::pair<int,long long>& lh, const std::pair<int, long long>& rh) const
		{
			return lh.second < rh.second;
		}
	} customLess;
	std::sort(newNumbers.begin(), newNumbers.end(), customLess);

	long long length = newNumbers.size();
	long long optimum = 0;
	for (long long i = 0; i < length-1; i++) {
		if (length - i < optimum) break;
		for (long long j = length-1; j > i; j--) {
			if (newNumbers[j].second - newNumbers[i].second <= limit) {
				optimum = (j - i+1 > optimum) ? (j - i+1) : optimum;
				break;
			}
		}
	}
	return optimum;
}

int main() {
	long long numbersN, limit,element;
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
	long long result = findMaximumElements(crises, limit);
	std::cout << result;
}