
#include <iostream>
#include <algorithm>
#include <vector>

std::pair<std::vector<long long int>,long long int> commonIndex(std::vector<long long int> mountain, std::vector<std::pair<long long int,long long int>> moves) {
	int* array = new int[mountain.size()];

	for (int i = 0; i < mountain.size(); ++i) {
		array[i] = 0;
	}

	for (int i = 0; i < moves.size(); ++i) {
		for (int j = moves[i].first - 1; j < moves[i].second; ++j) {
			array[j]++;
		}
	}
	for (int i = 0; i < mountain.size(); ++i) {
		std::cout << array[i] << ";";
	}
	std::cout << std::endl;
	
	std::vector<long long int> maxIndex;
	long long int max = array[0];
	for (int i = 0; i < mountain.size(); ++i) {
		if (max <= array[i]){
			max = array[i];
		}
	}

	for (int i = 0; i < mountain.size(); ++i) {
		if (max == array[i]) {
			maxIndex.push_back(i + 1);
		}
	}
	
	delete[] array;
	return std::make_pair(maxIndex, max);
}

std::vector<std::pair<long long int, long long int>> setIndex(std::vector<long long int> mountain, std::vector<std::pair<long long int, long long int>> moves, int m) {
	int* array = new int[mountain.size()];

	for (int i = 0; i < mountain.size(); ++i) {
		array[i] = 0;
	}
	for (int i = 0; i < moves.size(); ++i) {
		for (int j = moves[i].first - 1; j < moves[i].second; ++j) {
			array[j]++;
		}
	}

	std::vector<std::pair<long long int,long long int>> setIndex;
	for (int i = 0; i < mountain.size(); ++i) {
		if (array[i] == m) {
			std::pair<long long int, long long int> translate = std::make_pair(array[i], mountain[i]);
			setIndex.push_back(translate);
		}
	}
	

	delete[] array;
	return setIndex;
}

long long int findMaxIndex(std::vector<std::pair<long long int, long long int>> vec) {
	long long int max = vec[0].second;
	long long int maxIndex = 0;
	for (int i = 0; i < vec.size(); ++i) {
		if (max < vec[i].second) {
			max = vec[i].second;
			maxIndex = i;
		}
	}
	return maxIndex;
}


int main() {
	long long int N; 
	long long int M; 
	long long int K; 
	long long int l;
	long long int r;
	long long int current;
	std::cin >> N;
	std::cin >> M;
	std::cin >> K;

	std::vector<long long int> mountain;
	std::vector<std::pair<long long int,long long int>> moves;

	for (int i = 0; i < N; ++i) {
		std::cin >> current;
		mountain.push_back(current);
	}

	for (int i = 0; i < M; ++i) {
		std::cin >> l;
		std::cin >> r;
		std::pair<int, int> curr = std::make_pair(l,r);
		moves.push_back(curr);
	}
	long long int maxIter = commonIndex(mountain, moves).second;
	std::vector<long long int> maxIndex = commonIndex(mountain, moves).first;
	while (maxIter > 0) {
		std::vector<std::pair<long long int, long long int>> currMost = setIndex(mountain, moves, maxIter);
		
		while(K > 0){
			long long int currMaxIndex = findMaxIndex(currMost);
			long long int foundIndex = 0;
			for (int i = 0; i < mountain.size(); ++i) {
				if (currMost[currMaxIndex].second == mountain[i]) {
					foundIndex = i;
				}
			}
			if (mountain[foundIndex] <= 0) {
				break;
			}
			else {
				std::cout << K << ";";
				mountain[foundIndex]--;
				K--;
			}
		}
		maxIter--;
	}	
	for (int i = 0; i < mountain.size(); ++i) {
		std::cout << mountain[i];
	}
	long long int sum = 0;
	for (int i = 0; i < moves.size(); ++i) {
		for (int j = moves[i].first - 1; j < moves[i].second; ++j) {
			sum += mountain[j];
		}
	}

	std::cout << sum - 1;
	return 0;
}